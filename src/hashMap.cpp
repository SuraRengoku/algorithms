#include<iostream>
#include<string>
#include<vector>

struct Pair{
    public:
    int key;
    std::string val;
    Pair(int key, std::string val){
        this->key = key;
        this->val = val;
    }
};

class ArrayHashMap{
    private:
        std::vector<Pair*> buckets;
    public:
        ArrayHashMap(){
            buckets = std::vector<Pair*>(100);
        }
        ~ArrayHashMap(){
            for(const auto& bucket: buckets){
                delete bucket;
            }
            buckets.clear();
        }

        //哈希算法 哈希函数
        int hashFunc(int key){
            int index = key%100;
            return index;
        }

        std::string get(int key){
            int index = hashFunc(key);
            Pair *pair = buckets[index];
            if(pair == nullptr)
                return "";
            return pair->val;
        }

        void put(int key, std::string val){
            Pair *pair = new Pair(key,val);
            int index = hashFunc(key);
            buckets[index] = pair;
        }

        void remove(int key){
            int index = hashFunc(key);
            delete buckets[index];
            buckets[index] = nullptr;
        }
        
        auto pairSet()->std::vector<Pair *>{
            std::vector<Pair *> pairSet;
            for(const auto& element: buckets){
                if(element!=nullptr){
                    pairSet.push_back(element);
                }
            }
            return pairSet;
        }

        auto keySet()->std::vector<int>{
            std::vector<int> keySet;
            for(const auto& element: buckets){
                if(element!=nullptr){
                    keySet.push_back(element->key);
                }
            }
            return keySet;
        }

        auto valueSet()->std::vector<std::string>{
            std::vector<std::string> valueSet;
            for(const auto& element: buckets){
                if(element!=nullptr){
                    valueSet.push_back(element->val);
                }
            }
            return valueSet;
        }

        void print(){
            for(Pair *pair:this->buckets){
                std::cout<<pair->key<<"->"<<pair->val<<std::endl;
            }
        }
};

//为了应对哈希冲突，需要频繁对哈希表进行扩容，当负担因子（被占用数/总容量）超过0.75时需要考虑扩容
//可以改良哈希表，构造链式地址或者开放寻址的哈希表

class HashMapChaining{
    private:
        int size; //键值对数量
        int capacity; //哈希表容量
        double loadThres; //触发扩容的负载因子阈值
        int extendRatio; //扩容倍数
        std::vector<std::vector<Pair *>> buckets; //桶数组

    public:
        HashMapChaining(): size(0),capacity(4),loadThres(2.0/3.0),extendRatio(2){
            buckets.resize(capacity);
        }

        ~HashMapChaining(){
            for(auto &bucket: buckets){
                for(Pair *pair: bucket){
                    delete pair;
                }
            }
        }

        //哈希函数
        int hashFunc(int key){
            return key% capacity;
        }

        double loadFactor(){
            return (double)size/(double)capacity;
        }

        std::string get(int key){
            int index = hashFunc(key);
            for(Pair *pair : buckets[index]){
                if(pair->key==key){
                    return pair->val;
                }
            }
            return ""; //没有找到返回空
        }

        void put(int key, std::string val){
            if(loadFactor()>loadThres){
                extend();
            }
            int index=hashFunc(key);
            for(Pair *pair: buckets[index]){
                if(pair->key == key){
                    pair->val=val; //遇到指定key，更新value
                    return;
                }
            }
            buckets[index].push_back(new Pair(key,val));
            size++;
        }

        void remove(int key){
            int index=hashFunc(key);
            auto &bucket= buckets[index];
            for(int i=0;i<bucket.size();i++){
                if(bucket[i]->key==key){
                    Pair *tmp= bucket[i];
                    bucket.erase(bucket.begin()+i);
                    delete tmp; //释放内存
                    size--;
                    return;
                }
            }
        }

        void extend(){
            //暂存原哈希表
            std::vector<std::vector<Pair *>> bucketsTmp = buckets;
            capacity*=extendRatio;
            buckets.clear();
            buckets.resize(capacity);
            this->size=0;
            //搬运
            for(const auto& bucket: bucketsTmp){
                for(const auto& pair: bucket){
                    put(pair->key,pair->val);
                    delete pair;
                }
            }
        }

        void print(){
            for(auto& bucket:buckets){
                std::cout<<"[";
                for(Pair *pair:bucket){
                    std::cout<<pair->key<<"->"<<pair->val<<",";
                }
                std::cout<<"]";
            }
        }
};

class HashMapOpenAddressing{
    private:
        int size;
        int capacity=4;
        const double loadThres=2.0/3.0;
        const int extendRatio=2;
        std::vector<Pair *> buckets;
        Pair *TOMBSTONE=new Pair(-1,"-1"); //懒删除标记

    public:
        HashMapOpenAddressing():size(0),buckets(capacity,nullptr){
            //创建大小为capactity，初始值为nullptr的buckets vector
        }

        ~HashMapOpenAddressing(){
            for(Pair *pair: buckets){
                if(pair!= nullptr && pair!=TOMBSTONE){
                    delete pair;
                }
            }
            delete TOMBSTONE;
        }

        int hashFunc(int key){
            return key% capacity;
        }

        double loadFactor(){
            return (double)size/(double)capacity;
        }

        int findBucket(int key){
            int index=hashFunc(key);
            int firstTombstone=-1;
            //线性探测，遇到空桶时跳出
            while(buckets[index]!=nullptr){
                //遇到key，返回桶索引
                if(buckets[index]->key==key){
                    if(firstTombstone!=-1){
                        //在遇到key之前遇到删除标记，将键值对移动到索引处
                        buckets[firstTombstone]=buckets[index];
                        buckets[index]=TOMBSTONE;
                        return firstTombstone;
                    }
                    return index;//遇到key,返回桶索引
                }
                //记录遇到的首个删除标记
                if(firstTombstone==-1&&buckets[index]==TOMBSTONE)
                    firstTombstone=index;
                index=(index+1)%capacity;//环形链表
            }
            return firstTombstone==-1?index:firstTombstone;//没找到key,返回添加点索引
        }

        std::string get(int key){
            int index=findBucket(key);
            if(buckets[index]!=nullptr&&buckets[index]!=TOMBSTONE){
                return buckets[index]->val;
            } 
            return "";
        }

        void put(int key,std::string val){
            if(loadFactor()>loadThres)
                extend();
            int index=findBucket(key);//相同键会覆盖，不同键会找出空位索引
            if(buckets[index]!=nullptr&&buckets[index]!=TOMBSTONE){
                buckets[index]->val=val;
                return;
            }
            buckets[index]=new Pair(key,val);
            size++;
        }

        void remove(int key){
            int index=findBucket(key);
            if(buckets[index]!=nullptr&&buckets[index]!=TOMBSTONE){
                delete buckets[index];
                buckets[index]=TOMBSTONE;
                size--;
            }    
        }

        void extend(){
            std::vector<Pair *> bucketsTmp=buckets;
            capacity*=extendRatio;
            buckets=std::vector<Pair *>(capacity,nullptr);
            this->size=0;
            for(Pair *pair: bucketsTmp){
                if(pair!=nullptr&&pair!=TOMBSTONE){
                    put(pair->key,pair->val);
                    delete pair;
                }
            }
        }

        void print(){
            for(const auto& pair:buckets){
                if(pair!=nullptr){
                    std::cout<<"nullptr"<<std::endl;
                }else if(pair==TOMBSTONE){
                    std::cout<<"TOMBSTONE"<<std::endl;
                }else{
                    std::cout<<pair->key<<"->"<<pair->val<<std::endl;
                }
            }
        }
};

//为了避免哈希冲突，应该设计高效的哈希函数
/* 加法哈希 */
int addHash(std::string key) {
    long long hash = 0;
    const int MODULUS = 1000000007;
    for (unsigned char c : key) {
        hash = (hash + (int)c) % MODULUS;
    }
    return (int)hash;
}

/* 乘法哈希 */
int mulHash(std::string key) {
    long long hash = 0;
    const int MODULUS = 1000000007;
    for (unsigned char c : key) {
        hash = (31 * hash + (int)c) % MODULUS;
    }
    return (int)hash;
}

/* 异或哈希 */
int xorHash(std::string key) {
    int hash = 0;
    const int MODULUS = 1000000007;
    for (unsigned char c : key) {
        hash ^= (int)c;
    }
    return hash & MODULUS;
}

/* 旋转哈希 */
int rotHash(std::string key) {
    long long hash = 0;
    const int MODULUS = 1000000007;
    for (unsigned char c : key) {
        hash = ((hash << 4) ^ (hash >> 28) ^ (int)c) % MODULUS;
    }
    return (int)hash;
}

//目前主流哈希算法为SHA-2，SHA-3（尚未普及）
//MD-5和SHA-1已被破解