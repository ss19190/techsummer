#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

int main(int argc, char const *argv[])
{
    std::ifstream file("input.txt");
    int n, length;
    std::string start, city1, city2;
    std::map<std::string, int> length_with_city;
    std::map<std::string, std::map<std::string, int>> distances;

    if(file.is_open()){
        file >> n >> start;
        
        for(;n > 0;n--){

            for(int i = 0; i < n - 1; i++){
                file >> city1 >> city2 >> length;
                length_with_city[city2] = length;
                //std::cout << "\ncity2: " << city2 << "\nlength: " << length;
            }

            distances[city1] = length_with_city;
            //std::cout << "\ncity1: " << city1;
            for (const auto& pair : distances) {
            std::cout << "Key: " << pair.first << ", Value: " << std::endl;
            for (const auto& inner_pair : pair.second) {
                std::cout << "    Inner Key: " << inner_pair.first << ", Inner Value: " << inner_pair.second << std::endl;
            }
        }

        }

        file.close();
    } else
        std::cout << "Unable to open the file";
    return 0;
}
