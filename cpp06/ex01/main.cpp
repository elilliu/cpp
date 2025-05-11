#include "Serializer.hpp"
#include "Data.hpp"

int	main(void)
{
	Data		data;

	data.i = 42;
	data.c = '*';
	data.str = "Bonsoir";

	uintptr_t	raw = Serializer::serialize(&data);
	Data*		ptr = Serializer::deserialize(raw);

	std::cout << "ptr->i: " << ptr->i << std::endl;
	std::cout << "ptr->c: " << ptr->c << std::endl;
	std::cout << "ptr->str: " << ptr->str << std::endl;

	return (0);
}
