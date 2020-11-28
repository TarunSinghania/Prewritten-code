struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};


unordered_map<long long, int, custom_hash> safe_map;



need something more fast ?

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

gp_hash_table<long long, int, custom_hash> safe_hash_table;


unordered_maplinear insertion:                                  0.689846
cc_hash_tablelinear insertion:                                  0.408233
gp_hash_tablelinear insertion:                                  0.256131

unordered_maplinear read/write:                                 1.69783
cc_hash_tablelinear read/write:                                 0.202474
gp_hash_tablelinear read/write:                                 0.26842

unordered_maprandom insertion:                                  2.90184
cc_hash_tablerandom insertion:                                  3.15129
gp_hash_tablerandom insertion:                                  0.56553

unordered_maprandom read/write:                                 2.02336
cc_hash_tablerandom read/write:                                 0.333415
gp_hash_tablerandom read/write:                                 0.403486
