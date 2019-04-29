//
// Created by kevin on 15/04/19.
//

#ifndef GLADIATORS_GBP_CLIENT_H
#define GLADIATORS_GBP_CLIENT_H


#include <QtCore/QJsonArray>

class Client{

public:

    static void retrieveGladiators();
    static void retrieveTowers();
    static void sendGladiatorsData();
    static void sendTowersData();
    static void reset();

private:

    static QJsonArray getGladiators();
    static QJsonArray getTowers();
    static void postGladiators();
    static void postTowers();
    static void postReset();

};


#endif //GLADIATORS_GBP_CLIENT_H
