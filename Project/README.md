# An exploration of recipes

As the standard of living greatly increased in the past century, people have more access to food than ever. Exotic ingredients, which used to be prohibitive and scarce, become more and more accessible to the general public. This, along with the increase in communication, created a globalization of the recipes. We analyze a collection of recipes, trying to gain more insights into how various dishes are related and also into the recipes themselves.

## Getting Started

The following instructions will provide you all the necessary information in order to successfully run the project

### Data set

Throughout the project we used a subset of the Recipes 1M dataset that can be downloades from the * [dataset download page]( http://im2recipe.csail.mit.edu/dataset/) . 

### Python Libraries

The majority of the project was coded in Python 3.7. In addition of the usual libraries, several specific libraries need to be installed :

```
operator 
pickle 
scipy
json
networkx

```

### Notebooks and scripts

Once the previous libraries are successfully installed, you need to run several notebook for the project : 

1. Building the graphs


```build_graphs.ipynb ```  :  this notebook will build the two graphs - ingredients and recipes based. It uses the ```generate_recipes_graph.cpp``` script developed in C++ for computation reasons. The execution this script is completely included in the notebook. It also saves two recipes and ingredients dataframes and the ingredients graph as pickles and and a sparse matrix for the recipes graph as an ```.npz``` file. 

2. Analyze the graphs 

```analyze_graphs.ipynb``` : this notebook runs a graph analysis for the recipes and ingredients graphs (degree distribution, centrality, etc.).

3. Cooking time
```cooking_time.ipynb``` : this notebook performs the computation of the cooking time from the raw instructions test and performs some analysis on the results.


## Authors

Project realised for the EPFL EE-558 course : A network tour of data science. 
Team 10 : 
* **Furtuna Andrei Calin** 
* **Gafton Paul-Adrian** 
* **Mircea Sorin-Sebastian** 
* **Mocanu Alexandre** 

See also the list of [contributors](https://github.com/your/project/contributors) who participated in this project.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.


