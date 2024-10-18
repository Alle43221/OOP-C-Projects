//
// Created by Ale on 21.05.2024.
//

#ifndef GAMING_STORE_REPO_H
#define GAMING_STORE_REPO_H
#include "Joc.h"
#include "vector"
#include "fstream"
#include "cstring"

class Repo {
public:
    Repo(const string &path) : path(path) {
        load();
    }

    const vector<Joc> &getElems() const {
        return elems;
    }

private:
    void load(){
        ifstream f(path);
        char buffer[250], titlu[50], platforma[20];
        int pret, rating;
        elems.clear();
        while(f.get(buffer, 250)){
            char *p=strtok(buffer, ",");
            strcpy(titlu, p);
            p=strtok(NULL, ",");
            pret=atoi(p);
            p=strtok(NULL, ",");
            strcpy(platforma, p);
            p=strtok(NULL, ",");
            rating=atoi(p);
            Joc nou(titlu, pret, platforma, rating);
            elems.push_back(nou);
            f.get();
        }
        f.close();
    }
    string path;
    vector<Joc> elems;
};


#endif //GAMING_STORE_REPO_H
