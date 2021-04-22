#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache;
    
    if(cacheSize == 0)
        return cities.size()*5;
    
    for (auto it = cities.begin(); it != cities.end(); it++)
        transform(it->begin(), it->end(), it->begin(), ::toupper);

    
    for(int i=0; i<cities.size(); i++) {
        auto it = find(cache.begin(), cache.end(), cities[i]);
        if(it == cache.end()) {
            if(cache.size()<cacheSize) {
                cache.push_back(cities[i]);
            }
            else{
                cache.erase(cache.begin());
                cache.push_back(cities[i]);
            }
            answer += 5;
        }
        else {
            cache.erase(it);
            cache.push_back(cities[i]);
            answer += 1;
        }
    }
    
    return answer;
}
