class RandomizedSet {
public:
    vector<int> v;        //Stroes values
    unordered_map<int, int> mp; //Stores pos
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val) != mp.end()) {
            return false;
        }
        v.push_back(val);
        mp[val]=v.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end()) return false;
        //val is present

        int ind=mp[val];
        int last=v.size()-1;    //last index
        int lastVal=v[last];

        swap(v[ind], v[last]);     //swapping bith because we want o(1)
        
        mp[lastVal]=ind;     //we swap last element with the deired one bit we have to also update in map as well so put lastval in map in index pos
        v.pop_back();
        
        mp.erase(val);     //val ->index(position)
        return true;
    }
    
    int getRandom() {
        if(v.size()==0) return -1;
        int ind=rand() % v.size();        // to get the random value in vector in the raange
        return v[ind];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */