#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include <queue>
#include <map>

using namespace std;


class Edge {
	public:
		string from;
		string to;

		Edge(string curr_from, string curr_to) {
			from = curr_from;
			to = curr_to;
		}
};


class HaffmanTree {
public:
	HaffmanTree(vector<pair<int, string>> dict_letters) {
		letters = dict_letters;
		tree = build_haffman_tree();
		root = get_root(tree);
	}

	string encode_processing(string word) {
		string code;
		set<string> visited;
		string start = root;
		deque<string> queue_1;
		for (char letter : word) {
			queue_1.push_back(start);
			while (!queue_1.empty()) {
				string node = queue_1.front();
				queue_1.pop_front();
				if (visited.count(node) == 0) {
					code += encoding(node, letter, tree);
					if (node.size() == 1 and node.find(letter) != string::npos) {
						visited.clear();
						queue_1.clear();
					}
					else {
						if (!tree[node].empty()){
							queue_1.push_back(tree[node][0]);
							queue_1.push_back(tree[node][1]);
						}
						visited.insert(node);
					}
				}
			}
		}
		return code;
	}

	string decode_processing(string row) {
		int count = 0;
		string result;
		string letter = root;
		while (count < row.size()) {
			char digit = row[count];
			if (digit == '0') {
				letter = tree[letter][0];
			}
			else {
				letter = tree[letter][1];
			}
			if (letter.size() == 1) {
				result += letter;
				letter = root;
			}
			count += 1;
		}
		return result;
	}

	map<string, string> get_all_codes() {
		map<string, string> codes;
		for (auto letter : letters) {
			codes[letter.second] = encode_processing(letter.second);
		}
		return codes;
	}

private:
	vector<pair<int, string>> letters;
	map<string, vector<string>> tree;
	string root;


	static bool compare_root(string node_1, string node_2) {
		return node_1.size() > node_2.size();
	}


	static string get_root(map<string, vector<string>> tree) {
		vector<string> keys;
		for (auto key : tree) {
			keys.push_back(key.first);
		}
		sort(keys.begin(), keys.end(), compare_root);
		return keys[0];
	}


	static map<string, vector<string>> tree_adjacency_list(vector<Edge> tree_edges) {
		map<string, vector<string>> adjacency_list;
		for (Edge edge : tree_edges) {
			adjacency_list[edge.from] = vector<string>{};
			adjacency_list[edge.to] = vector<string>{};
		}
		for (Edge edge : tree_edges) {
			adjacency_list[edge.from].push_back(edge.to);
		}
		return adjacency_list;
	}


	map<string, vector<string>> build_haffman_tree() {
		vector<Edge> edges_tree;
		priority_queue<pair<int, string>, 
			vector<pair<int, string>>, 
			greater<pair<int, string>>> free_nodes;
		for (pair<int, string> node : letters) {
			free_nodes.push(node);
		}
		while (free_nodes.size() > 1) {
			pair<int, string> node_1 = free_nodes.top();
			free_nodes.pop();
			pair<int, string> node_2 = free_nodes.top();
			free_nodes.pop();
			pair<int, string> parent = {node_1.first + node_2.first, node_1.second + node_2.second};
			free_nodes.push(parent);
			
			edges_tree.push_back(Edge(parent.second, node_1.second));
			edges_tree.push_back(Edge(parent.second, node_2.second));
		}
		return tree_adjacency_list(edges_tree);
	}


	static string encoding(string node, char letter, map<string, vector<string>> tree) {
		if (node.size() > 1) {
			if (tree[node][0].find(letter) != string::npos) {
				return "0";
			}
			else if (tree[node][1].find(letter) != string::npos) {
				return "1";
			}
		}
		return "";
	}
};

//baf a
//ba a
//f a
//b a
//a a
//baf b
//ba b
//f b
//b b
//baf f
//ba f
//f f

//
//int main() {
//	vector<pair<int, string>>  letters = { {15, "a"}, {7, "b"}, {23, "f"}};
//	HaffmanTree haffman_tree(letters);
//	cout << haffman_tree.encode_processing("abf") << endl;
//	//cout << haffman_tree.decode_processing("1101100101000010") << endl;
//	//for (auto i : haffman_tree.get_all_codes()) {
//	//	cout << i.first << " " << i.second << endl;
//	//}
//	return 0;
//}