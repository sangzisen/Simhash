//
// Created by Sang Zisen on 11/13/17.
//

#ifndef SIMHASH_SIMHASH_H
#define SIMHASH_SIMHASH_H


#include <stdio.h>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Simhash
{
public:
    Simhash(){
        std::vector<uint64_t> tvec;
        tvec.push_back(0);
        part_1.insert({0, tvec});
        part_2.insert({0, tvec});
        part_3.insert({0, tvec});
        part_4.insert({0, tvec});
    };
    Simhash(const std::unordered_map<uint16_t, std::vector<uint64_t>>& part_1, const std::unordered_map<uint16_t, std::vector<uint64_t>>& part_2, const std::unordered_map<uint16_t, std::vector<uint64_t>>& part_3, const std::unordered_map<uint16_t, std::vector<uint64_t>>& part_4){
        this->part_1 = part_1;
        this->part_2 = part_2;
        this->part_3 = part_3;
        this->part_4 = part_4;
    }
//
//    ~Simhash(){
//        this->part_1.clear();
//        this->part_2.clear();
//        this->part_3.clear();
//        this->part_4.clear();
//    }

    size_t HammingDistance(const uint64_t a, const uint64_t b);
    bool isExists(const uint64_t);
    void serialize();

private:
    std::unordered_map<uint16_t, std::vector<uint64_t >> part_1, part_2, part_3, part_4;
    std::unordered_map<uint16_t, std::vector<uint64_t >>::iterator pos_1, pos_2, pos_3, pos_4;
    std::string map_file_path_1 = "map.obj/map_part_1";
    std::string map_file_path_2 = "map.obj/map_part_2";
    std::string map_file_path_3 = "map.obj/map_part_3";
    std::string map_file_path_4 = "map.obj/map_part_4";
    uint16_t npart_1, npart_2, npart_3, npart_4;
};


#endif //SIMHASH_SIMHASH_H


