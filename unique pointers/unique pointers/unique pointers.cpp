#include <iostream>
#include <vector>
#include <memory>
class Test
{
	int data;
public:
	Test() :data(0) { std::cout << "\tTest constructor (" << data << ")" << std::endl; }
	Test(int data) :data(data) { std::cout << "\tTest constructor (" << data << ")" << std::endl; }
	int get_data()const { return data; }
	~Test() { std::cout << "\tTest destructor (" << data << ")" << std::endl; }
};
void fill(std::vector<std::shared_ptr<Test>>& vec,int num)
{
	for (int i = 0; i < num; i++)
	{
		int aux;
		std::cout << "Enter data point [" << i << "]" << std::endl;
		std::cin >> aux;
		vec.emplace_back(std::make_shared<Test>(aux));
	}
}
std::unique_ptr<std::vector<std::shared_ptr<Test>>> make()
{
	return std::make_unique<std::vector<std::shared_ptr<Test>>>();
}
void display(const std::vector<std::shared_ptr<Test>>& vec)
{
	for (int i = 0; i < vec.size(); i++)
		std::cout << vec[i]->get_data() << std::endl;
}
int main()
{
	std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr;
	vec_ptr = make();
	std::cout << "How many data points you want to enter:" << std::endl;
	int num;
	std::cin >> num;
	fill(*vec_ptr,num);
	display(*vec_ptr);
}

