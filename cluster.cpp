#include "cluster.h"
#include "point.h"
cluster::cluster()
{

}
cluster :: cluster(int id_cluster, point pt)
    {
        this->id_cluster = id_cluster;

        int total_values = pt.getTotalValues();

        for(int i = 0; i < total_values; i++)
            central_values.push_back(pt.getValue(i));

        points.push_back(pt);
    }

    void cluster :: addPoint(point pt)
    {
        points.push_back(pt);
    }

    bool cluster :: removePoint(int id_point)
    {
        int total_points = points.size();

        for(int i = 0; i < total_points; i++)
        {
            if(points[i].getID() == id_point)
            {
                points.erase(points.begin() + i);
                return true;
            }
        }
        return false;
    }

    double cluster :: getCentralValue(int index)
    {
        return central_values[index];
    }

    void cluster :: setCentralValue(int index, double value)
    {
        central_values[index] = value;
    }

    point  cluster ::getPoint(int index)
    {
        return points[index];
    }

    int cluster:: getTotalPoints()
    {
        return points.size();
    }

    int cluster:: getID()
    {
        return id_cluster;
    }
