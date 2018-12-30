
  ///////////////////////////////////////////
  //                                       //
  //       Created By: Piyush Yadav        //
  //         K-nearest neighbour.          //
  //                                       //
  ///////////////////////////////////////////


#include"iostream"
#include"math.h"
using std::cout;
using std::cin;
using std::endl;
bool Classify(int predict[]);

//Features Red and Green.

const int red[10][2]={{1,6},{1,8},{2,6},{2,7},{2,8},{3,6},{3,7},{3,9},{4,7},{4,8}};
const int green[10][2]={{7,1},{7,2},{8,1},{8,4},{8,3},{9,1},{9,2},{9,4},{10,1},{10,3}};

int main(){
    
    //Test data used by the classifier to predict the category.
    
    int predict[2]={6,6};
    
    //Checking the return value by the Classifier.
    
    if(Classify(predict)==0)
      cout<<"Red"<<endl;
    else
      cout<<"Green"<<endl;
    return 0;
}

//Classifier function takes test data as argument.

bool Classify(int predict[]){
    
    bool label(0);
    int distance(0);
    int bestRed(0);
    
    // Formula for getting the distance between  the test data and the feature data on the graph d=(X2-X1)^2+(Y2-Y1)^2.
    
    bestRed=(predict[0]-red[0][0])*(predict[0]-red[0][0])+(predict[1]-red[0] [1])*(predict[1]-red[0][1]);
    
    //getting distance of the test point from the Red feature points on the graph and extracting the shortest distance.
    
    for(int a(1);a<=7;a++){
        
    // d=(X2-X1)^2+(Y2-Y1)^2.
        
        distance=(predict[0]-red[a][0])*(predict[0]-red[a][0])+(predict[1]-red[a][1])*(predict[1]-red[a][1]);
        if(distance<bestRed){
          bestRed=distance;
          label=0;
      }
    }
    
     //getting distance of the test point from the Green feature points on the graph and comparing it with the shortest Red feature distance extracted it the previous loop.
    
     for(int a(0);a<=7;a++){
        
     // d=(X2-X1)^2+(Y2-Y1)^2
        
        distance=(predict[0]-green[a][0])*(predict[0]-green[a][0])+(predict[1]-green[a][1])*(predict[1]-green[a][1]);
        if(distance<bestRed){
           label=1;
      }
   }
    
   // Specifying the category of the test data 
    
   return label;
}