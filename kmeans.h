#ifndef KMEANS_H
#define KMEANS_H
#include<point.h>
#include<cluster.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
using namespace std;
class kmeans
{
private:
    int K; // number of clusters
    int total_values, total_points, max_iterations;
    vector<cluster> clusters;

    // return ID of nearest center (uses euclidean distance)
    int getIDNearestCenter(point pt);
public:
    kmeans();
    kmeans(int K, int total_points, int total_values, int max_iterations);
    void run(vector<point> & points);
};

#endif // KMEANS_H
