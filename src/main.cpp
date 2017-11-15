#include <iostream>
#include "simhash.h"
#include <unordered_map>
#include <vector>
#include <fstream>

using namespace std;



int main(){
    clock_t start, finish;
    start = clock();


    string in_file = "/Users/Sang/Desktop/Dechash/0";
    string out_file = "./results.txt";
//    file = "/Users/Sang/Desktop/test.txt";


    ifstream infile;
    infile.open(in_file.data());
    string hash;
    vector<uint64_t> hashes;
    vector<size_t> useless;
    while(getline(infile, hash)){
//     uint64_t tmp = std::stoi(hash);
     hashes.push_back(stoull(hash.c_str()));
    }
    infile.close();
    uint64_t n_hash = hashes[0];
    vector<uint64_t> tvec;
    tvec.push_back(n_hash);


    Simhash simhash;

    size_t count = hashes.size();
    cout << "Total number of data: "<< count << endl;

    bool exists;
    for(size_t i = 0; i < count; i++){
        exists = simhash.isExists(hashes[i]);
        if(!exists) useless.push_back(i);
    }

    ofstream outfile;
    outfile.open(out_file);
    size_t result_size = useless.size();
    cout << "Surplus number of data: "<< result_size << endl;
    for(size_t i = 0; i < result_size; i++){
//        cout << useless[i] << endl;
        outfile << useless[i] << endl;
    }

    finish = clock();
    double duraton = (double) (finish - start) / CLOCKS_PER_SEC;
    cout << "用时" << duraton << "秒" << endl;
    simhash.serialize();

}

