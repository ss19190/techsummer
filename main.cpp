#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>

int main(int argc, char const *argv[])
{
    std::ifstream file("input.txt");
    int n, k, length, distance, max_distance = 0;
    std::string start, city1, city2, next_city;
    std::unordered_map<std::string, int> length_with_city;
    std::unordered_map<std::string, std::unordered_map<std::string, int>> distances;
    std::vector<std::string> path;
    int length_of_path = 0;
    bool first;

    if (file.is_open())
    {
        file >> n >> start;
        k = n;
        path.push_back(start);
        for (; n > 0; n--)
        {

            for (int i = 0; i < n - 1; i++)
            {
                file >> city1 >> city2 >> length;
                if (length > max_distance)
                    max_distance = length;
                length_with_city[city2] = length;
                // std::cout << "\ncity2: " << city2 << "\nlength: " << length;
            }

            distances[city1] = length_with_city;
            // std::cout << "\n\ncity1: \n" << city1;
        }

        file.close();
    }
    else
        std::cout << "Unable to open the file";

    for (; k > 0; k--)
    {
        distance = max_distance;
        for (const auto &pair1 : distances)
        {
             //std::cout << "\nFirst Key: " << pair1.first;

            if (pair1.first == start)
            {
                for (const auto &pair2 : pair1.second)
                {
                    if (pair2.second < distance)
                    {
                        distance = pair2.second;
                        next_city = pair2.first;
                        first = true;
                        std::cout<< "\nloop 1, " << next_city << ", " << distance;
                    }
                     //std::cout << "Key: " << pair2.first << ", Value: " << pair2.second << std::endl;
                }
            }
            else
            {
                for (const auto &pair2 : pair1.second)
                {
                     //std::cout << "Key: " << pair2.first << ", Value: " << pair2.second << std::endl;

                    if (pair2.first == start)
                    {
                        if (pair2.second < distance)
                        {
                            distance = pair2.second;
                            next_city = pair1.first;
                            first = false;
                            std::cout<< "\nloop 2, " << next_city << ", " << distance;
                        }
                         //std::cout << "Key: " << pair2.first << ", Value: " << pair2.second << std::endl;
                    }
                }
            }
        }

        length_of_path += distance;
        std::cout << " Length of path: " << length_of_path;

        if (first){
            distances.erase(start);
            }
        else{
            distances[next_city].erase(start);
        }
        path.push_back(next_city);
        start = next_city;
        std::cout << "\nstart: " << k << start;
        std::cout << "\nnext city: " << next_city;
    }

    for (const auto &element : path)
    {
        std::cout << element << " ";
    }

    return 0;
}
