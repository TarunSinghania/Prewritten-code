unordered_map<int,int>mp;

mp.reserve(1024);
mp.max_load_factor(0.25);

With this two lines unordered_map become about 10 times faster. You can replace 1024 with another suitable power of two.(it depends on number of insert s you will do).



using namespace std;
const int maxn=200050;
int a[maxn];
unordered_map<int,int> dp;
int main(){
    dp.reserve(maxn);
    dp.max_load_factor(0.25);


Get or set maximum load factor
The first version (1) returns the current maximum load factor for the unordered_set container.
The second version (2) sets z as the new maximum load factor for the unordered_set container.

The load factor is the ratio between the number of elements in the container (its size) and the number of buckets (bucket_count).

By default, unordered_set containers have a max_load_factor of 1.0.

The load factor influences the probability of collision in the hash table (i.e., the probability of two elements being located in the same bucket). The container uses the value of max_load_factor as the threshold that forces an increase in the number of buckets (and thus causing a rehash).
