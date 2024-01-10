#include <iostream>
#include <string>
using namespace std;

class Movie
{
public:
	Movie();
	// Default constructor: initializes to dummy values

	Movie(string nameVal, string ratingVal, double revenueVal);
	// Initializes all fields

	string getMovieName();
	// Postcondition: returns the name of the movie

	string getMovieRating();
	// Postcondition: returns the movie rating

	double getMovieRevenue();
	// Postcondition: returns the movie revenue

	void output();
	// Postcondition: Prints all member variables to standard output

	void input();
	// Precondition: Rating is a valid value
	// Postcondition: User manually sets all member variables

	void setMovieName(string newName);
	// Postcondition: Movie name is set to a new value

	void setMovieRating(string newRating);
	// Precondition: Rating is a valid value
	// Postcondition: Movie rating is set to a new value

	void setMovieRevenue(double newRevenue);
	// Postcondition: Movie revenue is set to a new value

	double movieShowing(int n);
	// Precondition: number of movie viewers is provided
	// Postcondition: updates the amount of money that the
	// film has earned

	Movie mergeMovie(Movie m);
	// Precondition: Both movies have the same name
	// Postcondition: Merges the amount of money that the films have earned
	// and uses the most restrictive rating

private:
	string name;
	string rating;
	double revenue;

	void testRating();
	// Precondition: A rating value is tested
	// Postcondition: Ends the program if the rating is invalid
};

int main() {
	
	Movie testMovie, Gnome("Attack of the Gnomes", "PG-13", 8000);

	Gnome.output();
	cout<<testMovie.getMovieName()<<endl;
	cout<<testMovie.getMovieRating()<<endl;
	cout<<testMovie.getMovieRevenue()<<endl;

	testMovie.input();

	Movie newMovie;

	cout<<endl;
	newMovie.setMovieName("Dangerous Shark");
	newMovie.setMovieRating("PG");
	newMovie.setMovieRevenue(19200.90);
	newMovie.output();

	Gnome.movieShowing(12);
	cout<<Gnome.getMovieRevenue()<<endl;

	Movie otherGnome("Attack of the Gnomes", "R", 200), combinedGnome;
	combinedGnome = Gnome.mergeMovie(otherGnome);
	combinedGnome.output();



	return 0;
}

Movie::Movie()
	: name("Test Movie"), rating("G"), revenue(10)
	{/* Empty */}

Movie::Movie(string nameVal, string ratingVal, double revenueVal)
	: name(nameVal), rating(ratingVal), revenue(revenueVal)
	{
		testRating();
	}

string Movie::getMovieName() {
	return name;
}

string Movie::getMovieRating() {
	return rating;
}

double Movie::getMovieRevenue() {
	return revenue;
}

void Movie::output() {
	cout<<name<<endl;
	cout<<rating<<endl;
	cout<<revenue<<endl;
	cout<<endl;
}

void Movie::input() {
	cout<<"Enter movie name"<<endl;
	cin>>name;
	cout<<"Enter movie rating"<<endl;
	cin>>rating;
	cout<<"Enter movie revenue"<<endl;
	cin>>revenue;

	testRating();

}

void Movie::setMovieName(string newName) {

	name = newName;
}

void Movie::setMovieRating(string newRating) {

	rating = newRating;
	testRating();
}
	
void Movie::setMovieRevenue(double newRevenue) {

	revenue = newRevenue;
}

void Movie::testRating() {

	if(rating != "G" && rating != "PG" && rating != "PG-13" && rating != "R") {
		cout << "Illegal rating value!\n";
		exit(1);
	}
}

double Movie::movieShowing(int n) {

	revenue += (n * 12);

	return revenue;
}


Movie Movie::mergeMovie(Movie m) {

	Movie CombinedMovie;

	if(name == m.name) {
		CombinedMovie.name = name;
		CombinedMovie.revenue = revenue + m.revenue;
		if(rating == "R" || m.rating == "R")
			CombinedMovie.rating = "R";
		else if(rating == "PG-13" || m.rating == "PG-13")
			CombinedMovie.rating = "PG-13";
		else if(rating == "PG" || m.rating == "PG")
			CombinedMovie.rating = "PG";
		else if(rating == "G" || m.rating == "G")
			CombinedMovie.rating = "G";
	}
	else
		CombinedMovie.name = "Could not combine";

	return CombinedMovie;
}
