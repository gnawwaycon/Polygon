/*
Conway Wang 10/28/15
lab midterm cisc 2000
Driver file for the Polygon class
*/


/*Include directives for polygon date and name classes
 *
 */

#include "Polygon.h"
#include "Date.h"
#include "Name.h"

int main()
{
//function definitions to be called in the menus
    void displayStat(Polygon**, Date, Name);//displays summary statistics of all the polygons along with the name and date
    void deletePoly(Polygon**, int, int);//deletes a polygon with an index and number of polygons as integers being passed to the function
    bool valid(int);//checks if user choice for a polygon exists

    Polygon *rect[Polygon::getMAX_POLYGONS()];//array of pointers of the polygon class


    bool cont=true;//keeps asking for user input until they choose to exit
    int choice;//keeps track of what the user inputs as their choice
    int polyChoice;//keeps track of which polygon user wants drawn of data shown

    Date createdOn;//initializing object of type date
    Name createdBy;//initializing object of type name

    createdOn.input("What is the day you are creating these polygons?");

    cout << "Who is the creator of these polygons?" << endl;
    createdBy.input();

    while(cont)
    {
        cout << "What would you like to do?" << endl;
        cout << "1) Enter a polygon" << endl;
        cout << "2) Draw a polygon" << endl;
        cout << "3) Show data of a polygon" << endl;
        cout << "4) Show summary statistics" << endl;
        cout << "5) Delete a polygon" << endl;
        cout << "6) Exit" << endl;
        cin >> choice;

        switch(choice)//switch statement determines course of action
        {
        case 1:
            rect[Polygon::getNumPolygons()]=new Polygon;
            rect[Polygon::getNumPolygons()]->input();//calls input function on the index of the polygon array that user is on
            break;

        case 2:

            do {//choice checks if a polygon is in range
            cout << "Which one?" << endl;
            cin >> polyChoice;
            }while(!valid(polyChoice));

            rect[polyChoice-1]->draw();//finds polygon requested to draw
            break;

        case 3:

            do{
            cout << "Which one?" << endl;
            cin >> polyChoice;
            }while(!valid(polyChoice));

            (*rect[polyChoice-1]).displayInfo();//displays info of polygon requested
            break;

        case 4:
            displayStat(rect, createdOn, createdBy);//displays overall statistics and name and date
            break;

        case 5:

            do{
            cout << "Which one?" << endl;
            cin >> polyChoice;
            }while(!valid(polyChoice));

            deletePoly(rect, polyChoice, Polygon::getNumPolygons());
            break;

        case 6:
            cont=false;//stops the next iteration of the while loop
            break;

        default:
            cout << "Invalid choice enter another one" << endl;
            break;
        }
    }

}

void displayStat(Polygon *a[], Date createdOn, Name createdBy)
{
    cout << "Polygons created on: ";
    createdOn.display();//calls display on date object from user input passed to the function
    cout << " by: ";
    createdBy.display();//calls display on name object from user input passed to the function

    a[0]->displayData();//calls summary statistics which outputs static variables so any instance of the class is allowed
}

void deletePoly(Polygon *a[], int index, int numPoly)
{
    delete a[index-1];//deletes pointer from user input, summary statistics are updated by the destructor

    for(int x=index-1; x<numPoly-1; x++)//loops until second to last object is reached
    {
        a[x]=a[x+1];//shifting the pointers over by one
    }
}

bool valid(int c)
{
    bool inRange=false;

    int range=Polygon::getNumPolygons();//the range is the total number of polygons

    if(c>0&&c<=range)//must lie in the range
        inRange=true;

    return inRange;//if if statement isnt executed then the false value is returned
}
