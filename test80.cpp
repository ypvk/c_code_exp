#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
  string t;
  map<string, int> m_map;
  while(cin >> t)
  {
    cout << m_map[t] << endl;
    m_map[t]++;
  }
  map<string, int>::iterator it = m_map.begin();
  while(it != m_map.end())
  {
    cout << it->first << '\t' << it->second << endl;
    it++;
  }
  return 0;
}
