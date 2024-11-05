#include <SFML/Graphics.hpp>
#include <vector>
#include <stack>
#include <ctime>

void swap(std::vector<sf::RectangleShape>& arr, const int& i, const int& j)
{
	sf::Vector2f tmp = arr[i].getPosition();
	arr[i].setPosition(arr[j].getPosition());
	arr[j].setPosition(tmp);
	sf::RectangleShape temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;

}

void ExchangeSort(std::vector<sf::RectangleShape> & arr, int &i, int &j)
{
	if (i < arr.size() - 1)
	{
		arr[i].setFillColor(sf::Color::Yellow);
		if (j < arr.size())
		{
			if(j - 1 != i)
				arr[j - 1].setFillColor(sf::Color::Black);
			arr[j].setFillColor(sf::Color::Red);
			int h1 = abs(arr[i].getSize().y);
			int h2 = abs(arr[j].getSize().y);
			if (h1 > h2)
			{
				arr[j].setFillColor(sf::Color::Yellow);
				arr[i].setFillColor(sf::Color::Red);
				swap(arr, i, j);
			}
			j++;
	
		}
		else
		{
			arr[j - 1].setFillColor(sf::Color::Black);
			arr[i].setFillColor(sf::Color::Green);
			i++;
			j = i + 1;
		}
	}
	if(i == arr.size() - 1)
		arr[i].setFillColor(sf::Color::Green);
		
}
void selectionSort(std::vector<sf::RectangleShape>& arr, int &i, int &j, int &j_min)
{
	/*for(int i = 0; i < arr.size() - 1; i++)
	{
		int j_min = i;
		int j = i + 1;

		for( ; j < arr.size(); j++)
		{*/
	if (i < arr.size() - 1)
	{
		arr[j_min].setFillColor(sf::Color::Blue);
		arr[i].setFillColor(sf::Color::Yellow);
		if (j < arr.size())
		{
			if(j - 1 != i)
				arr[j - 1].setFillColor(sf::Color::Black);
			arr[j].setFillColor(sf::Color::Red);
			int h1 = abs(arr[j].getSize().y);
			int h2 = abs(arr[j_min].getSize().y);
			if (h1 < h2)
			{
				arr[j_min].setFillColor(sf::Color::Black);
				j_min = j;
			
			}
			j++;
		}
		else
		{
			if (j_min != j)
			{
				arr[j_min].setFillColor(sf::Color::Yellow);
				arr[i].setFillColor(sf::Color::Red);
				swap(arr, i, j_min);
			}
			arr[j_min].setFillColor(sf::Color::Black);
			arr[j - 1].setFillColor(sf::Color::Black);
			arr[i].setFillColor(sf::Color::Green);
			i++;
			j_min = i;
			j = i + 1;
		}
	}
	if (i == arr.size() - 1)
		arr[i].setFillColor(sf::Color::Green);
		/*}
		if(j_min != j)
			swap(arr, i, j_min);
	}*/
}

void quickSort(std::vector<sf::RectangleShape>& arr, std::stack<std::pair<int, int>>& diap, int &j, int& i)
{
	if (!diap.empty())
	{
		std::pair<int, int> LR = diap.top();

		int pivot = LR.second;
		arr[LR.first].setFillColor(sf::Color::Cyan);
		arr[pivot].setFillColor(sf::Color::Blue);

		if (j < LR.second)
		{
			if(j - 1 >= 0)
				arr[j - 1].setFillColor(sf::Color::Black);
			arr[j].setFillColor(sf::Color::Red);
			int h1 = abs(arr[j].getSize().y);
			int h2 = abs(arr[pivot].getSize().y);
			if (h1 < h2)
			{
				i++;
				arr[i].setFillColor(sf::Color::Red);
				arr[j].setFillColor(sf::Color::Yellow);
				swap(arr, i, j);
			}
			j++;
		}
		else
		{
			diap.pop();
			arr[i + 1].setFillColor(sf::Color::Green);
			arr[LR.second].setFillColor(sf::Color::Green);
			swap(arr, i + 1, LR.second);
			int pivotIndex = i + 1;
			if(pivotIndex - 1 > LR.first)
				diap.push({LR.first, pivotIndex - 1});
			if (pivotIndex + 1 < LR.second) 
				diap.push({ pivotIndex + 1, LR.second });
			if(!diap.empty())
			{	
				j = diap.top().first;
				i = diap.top().first - 1;
				
			}
			if (j >= LR.second && diap.empty())
				for (auto& elem : arr)
					elem.setFillColor(sf::Color::Green);
		}
	}
}
void bubleSort(std::vector<sf::RectangleShape>& arr, int&i, int &countRun)
{
	if (i < arr.size() - countRun)
	{
		if(i > 0)
			arr[i - 1].setFillColor(sf::Color::Black);
		arr[i].setFillColor(sf::Color::Red);
		int h1 = abs(arr[i].getSize().y);
		int h2 = abs(arr[i + 1].getSize().y);
		if (h1 > h2)
		{
			arr[i + 1].setFillColor(sf::Color::Black);
			arr[i].setFillColor(sf::Color::Red);
			swap(arr, i, i + 1);
		}
		i++;

	}
	else
	{
		countRun++;
		arr[i].setFillColor(sf::Color::Green);
		if(i > 0)
			arr[i - 1].setFillColor(sf::Color::Black);
		i = 0;
	}
	
}

int main()
{
	bool flag = true;
   sf::RenderWindow window (sf::VideoMode(1200,600),"sortings-algorithms");
	window.setFramerateLimit(20);
	std::vector<sf::RectangleShape> shapes(40);
	for(int i = 0; i < 40; i++)
	{
		shapes[i].setFillColor(sf::Color::Black);
		shapes[i].setSize(sf::Vector2f(20, -1 * (10 + rand() % 500)));
		shapes[i].setPosition(5 + 30 * i, 570);
	}
	int i = 0;
	int j = i + 1;
	int j_min = 0;
	int end = shapes.size() - 1;
	int jForQuick = 0;
	int iForQuick = -1;
	int countRun = 1;
	std::stack<std::pair<int,int>> diap;
	diap.push({i, end});
	
	while(window.isOpen())
	{
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		for(const auto& i : shapes)
			window.draw(i);
	/*	quickSort(shapes, diap, jForQuick, iForQuick);*/
		//ExchangeSort(shapes, i, j);
		//selectionSort(shapes, i, j, j_min);
		if(countRun < shapes.size() + 1)
			bubleSort(shapes, i, countRun);
		
		window.display();
		window.clear(sf::Color::White);
		
	}
}