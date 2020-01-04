#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <math.h>
#include <time.h>
using namespace std;

int main() {
    int num_recipes, num_ingredients, n, x;

    ifstream f("recipes_by_ingredients.txt");
    ofstream g("data/recipe_graph.txt");

    f >> num_recipes >> num_ingredients;
    map<int, float> *edges = new map<int, float>[num_recipes];
    vector<vector<int> > recipes_by_ingredients(num_ingredients);
    int *num_ing_recip = new int[num_recipes];
    for (int i = 0; i < num_ingredients; ++i) {
        f >> n;
        for (int j = 0; j < n; ++j) {
            f >> x;
            recipes_by_ingredients[i].push_back(x);
            ++num_ing_recip[x];
        }
    }

    // Build edges
    for (int i = 0; i < num_ingredients; ++i) {
        time_t curr_time = time(NULL);
        int n = recipes_by_ingredients[i].size();
        float idf = log((float)num_recipes / n);
        for (int j = 0; j < n - 1; ++j) {
            int ind1 = recipes_by_ingredients[i][j];
            // cout << j << "\n";
            for (int k = j + 1; k < n; ++k) {
                int ind2 = recipes_by_ingredients[i][k];
                edges[ind1][ind2] += idf * 2 / (num_ing_recip[ind1] + num_ing_recip[ind2]);
            }
        }
        cout << "Finished ingredient with " << n << " recipes in " << time(NULL) - curr_time << " seconds.\n";
    }

    for (int i = 0; i < num_recipes; ++i) {
        g << i << ": ";
        for (auto it = edges[i].begin(); it != edges[i].end(); ++it)
            g << "(" << it->first << "," << it->second << ") ";
        g << "\n";
    }

    delete[] num_ing_recip;
    delete[] edges;
    return 0;
}