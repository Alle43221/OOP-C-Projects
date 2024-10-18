//
// Created by Ale on 21.05.2024.
//

#ifndef GAMING_STORE_JOC_H
#define GAMING_STORE_JOC_H
#include "string"

using namespace std;

class Joc {
private:
    string titlu;
    int pret;
    string platforma;
    int rating;
public:

    Joc(const string &titlu, int pret, const string &platforma, int rating) : titlu(titlu), pret(pret),
                                                                              platforma(platforma), rating(rating) {}

    const string &getTitlu() const {
        return titlu;
    }

    const string &getPlatforma() const {
        return platforma;
    }

    int getRating() const {
        return rating;
    }

    int getPret() const {
        return pret;
    }
};


#endif //GAMING_STORE_JOC_H
