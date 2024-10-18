//
// Created by Ale on 21.05.2024.
//

#ifndef GAMING_STORE_SERVICE_H
#define GAMING_STORE_SERVICE_H

#include "Repo.h"
#include "algorithm"

class Service {
public:
    explicit Service(Repo &repo) : repo(repo) {}
    vector<Joc> get_all(){ return repo.getElems();}
    vector<Joc> sortPret(){
        vector<Joc> all=repo.getElems();
        sort(all.begin(), all.end(), [=](const Joc& a, const Joc& b){
            return a.getPret()<b.getPret();
        });
        return all;}
    vector<Joc> filterRating(int rating){
        vector<Joc> all=repo.getElems();
        vector<Joc> filtrate;
        copy_if(all.begin(), all.end(), back_inserter(filtrate), [rating](const Joc& a){
            return a.getRating()<rating;
        });
        return filtrate;}

private:
    Repo& repo;

};


#endif //GAMING_STORE_SERVICE_H
