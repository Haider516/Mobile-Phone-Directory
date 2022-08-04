#pragma once
#include<iostream>
#include<conio.h>
#include"queue.h"
#include"bst.h"
using namespace std;
void BFS(node1 root,int a)
{
	bool* visited = new bool[a];
	for (int i = 0; i < a; i++)
	{
		visited[i] = false;
	}
	Queue q;
// initially, no vertex has been visited

	visited[0] = true;
	q.Insert(root);// add vertex v to the queue
	while (!q.IsEmpty())
	{
		root = q.Remove();
		
		for (int i = 0; i < a; i++)
		{
				if (!visited[i])
				{
					visited[i] = true;
					q.Insert(root);
				}
		}
	}
}
