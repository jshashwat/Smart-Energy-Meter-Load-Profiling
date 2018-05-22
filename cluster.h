#ifndef CLUSTER_H
#define CLUSTER_H
#include "point.h"
#include<vector>
using namespace std;
class cluster
{
private:
    int id_cluster;
    vector<double> central_values;
    vector<point> points;

public:
    cluster(int id_cluster, point point);
    void addPoint(point pt);
    bool removePoint(int id_point);
    double getCentralValue(int index);
    void setCentralValue(int index, double value);
    point getPoint(int index);
    int getTotalPoints();
    int getID();
    cluster();
};

#endif // CLUSTER_H
