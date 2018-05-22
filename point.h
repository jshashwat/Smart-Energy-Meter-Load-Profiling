#ifndef POINT_H
#define POINT_H
#include<vector>
#include<string>
using namespace std;
class point
{
private:
    int id_point, id_cluster;
    vector<double> values;
    int total_values;
    string name;
public:
    point();

    point(int id_point, vector<double>& values, string name = "");
        int getID();
        void setCluster(int id_cluster);
        int getCluster();
        double getValue(int index);
        int getTotalValues();
        void addValue(double value);
        string getName();
};

#endif // POINT_H
