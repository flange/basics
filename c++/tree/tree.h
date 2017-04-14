#ifndef __TREE_H__
#define __TREE_H__

#include <deque>
#include <memory>
#include <sstream>
#include <string>

template <typename T>
class tree {
public:

	class tree_node {
	public:
		explicit tree_node(const T& t) : value{t} {}

		T value;
		std::shared_ptr<tree_node> left;
		std::shared_ptr<tree_node> right;
	};


	explicit tree() = default;


	std::string toString() {

		std::stringstream res;
		std::deque<tree_node> todo;

		todo.push_back(*root);

		while (!todo.empty()) {
			tree_node curr = todo.front();
			todo.pop_front();

			res << curr.value << " ";

			if (curr.left)
				todo.push_back(*(curr.left));

			if (curr.right)
				todo.push_back(*(curr.right));
		}

		return res.str();
	}





	std::shared_ptr<tree_node> root;

};

#endif // __TREE_H__
