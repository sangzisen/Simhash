//
// Created by Sang Zisen on 11/13/17.
//

#include "simhash.h"
#include <iostream>
#include <fstream>
//Compute HammingDistance between to 64bits hashcode
/**
 *
 * @param a, b  two 64bits hashcode to be computed
 * @param count HammingDistance between to hashcode
 *
 * */


size_t Simhash::HammingDistance(const uint64_t a, const uint64_t b){
    uint64_t res = a ^ b;
    size_t count(0);
    while(res){
        if(count > 3) return count;
        ++count;
        res &= res - 1;
    }
    return count;
}

bool Simhash::isExists(const uint64_t n_hash) {

    //Split the 64bits hashcode into 4 16bits hashcode
    size_t counter;


    npart_1 = n_hash >> 48;
    pos_1 = this->part_1.find(npart_1);
    if(pos_1 != part_1.end()){
        counter = pos_1->second.size();
        for (size_t i=0; i < counter; i++){
            if(HammingDistance(n_hash, pos_1->second[i]) <= 3) return false;
        }
    }

    npart_2 = n_hash << 16 >> 48;
    pos_2 = this->part_2.find(npart_2);

    if(pos_2 != part_2.end()){
        counter = pos_2->second.size();
        for (size_t i=0; i < counter; i++){
            if(HammingDistance(n_hash, pos_2->second[i]) <= 3) return false;
        }
    }


    npart_3 = n_hash << 32 >> 48;
    pos_3 = this->part_3.find(npart_3);

    if(pos_3 != part_3.end()){
        counter = pos_3->second.size();
        for (size_t i=0; i < counter; i++){
            if(HammingDistance(n_hash, pos_3->second[i]) <= 3) return false;
        }
    }


    pos_4 = this->part_4.find(npart_4);
    npart_4 = n_hash << 48 >> 48;

    if(pos_4 != part_4.end()){
        counter = pos_4->second.size();
        for (size_t i=0; i < counter; i++){
            if(HammingDistance(n_hash, pos_4->second[i]) <= 3) return false;
        }
    }


    vector<uint64_t > tmp;
    tmp.push_back(n_hash);

    if(pos_1 != part_1.end())
        pos_1->second.push_back(n_hash);
    else{
        part_1.insert({npart_1, tmp});
    }

    if(pos_2 != part_2.end())
        pos_2->second.push_back(n_hash);
    else{
        part_2.insert({npart_2, tmp});
    }

    if(pos_3 != part_3.end())
        pos_3->second.push_back(n_hash);
    else{
        part_3.insert({npart_3, tmp});
    }

    if(pos_4 != part_4.end())
        pos_4->second.push_back(n_hash);
    else{
        part_4.insert({npart_4, tmp});
    }

    return true;

}

void Simhash::serialize(){
    ofstream of;

    of.open(map_file_path_1);
    for(pos_1 = this->part_1.begin(); pos_1 != this->part_1.end(); ++pos_1){
        of << pos_1->first << "\t";
        for(int i = 0; i < pos_1->second.size(); i++) of << pos_1->second[i] << "\t";
        of << endl;
    }
    of.close();
    cout << "part_1 map has been saved!" << endl;

    of.open(map_file_path_2);
    for(pos_2 = this->part_2.begin(); pos_2 != this->part_2.end(); ++pos_2){
        of << pos_2->first << "\t";
        for(int i = 0; i < pos_2->second.size(); i++) of << pos_2->second[i] << "\t";
        of << endl;
    }
    of.close();
    cout << "part_2 map has been saved!" << endl;


    of.open(map_file_path_3);
    for(pos_3 = this->part_1.begin(); pos_3 != this->part_3.end(); ++pos_3){
        of << pos_3->first << "\t";
        for(int i = 0; i < pos_3->second.size(); i++) of << pos_3->second[i] << "\t";
        of << endl;
    }
    of.close();
    cout << "part_3 map has been saved!" << endl;


    of.open(map_file_path_4);
    for(pos_4 = this->part_4.begin(); pos_4 != this->part_4.end(); ++pos_4){
        of << pos_4->first << "\t";
        for(int i = 0; i < pos_4->second.size(); i++) of << pos_4->second[i] << "\t";
        of << endl;
    }
    of.close();
    cout << "part_4 map has been saved!" << endl;
}