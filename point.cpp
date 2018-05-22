#include "point.h"

point::point()
{

}
    point::point(int id_point, vector<double>& values, string name)
    {
        this->id_point = id_point;
        total_values = values.size();

        for(int i = 0; i < total_values; i++)
            this->values.push_back(values[i]);

        this->name = name;
        id_cluster = -1;
    }

    int point:: getID()
    {
        return id_point;
    }

    void point::setCluster(int id_cluster)
    {
        this->id_cluster = id_cluster;
    }

    int point::getCluster()
    {
        return id_cluster;
    }

    double point::getValue(int index)
    {
        return values[index];
    }

    int point::getTotalValues()
    {
        return total_values;
    }

    void point :: addValue(double value)
    {
        values.push_back(value);
    }

    string point ::  getName()
    {
        return name;
    }
