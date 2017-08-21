  映射和多重映射基于某一类型Key的键集的存在，提供对T类型的数据进行快速和高效的检索。
  对map而言，键只是指存储在容器中的某一成员。Map不支持副本键，multimap支持副本键。
  Map和multimap对象包涵了键和各个键有关的值，键和值的数据类型是不相同的，这与set不同。
  set中的key和value是Key类型的，而map中的key和value是一个pair结构中的两个分量。

1.map介绍
-----------
    使用map得包含map类所在的头文件：　
    #include <map> //注意，STL头文件没有扩展名.h
    
  1.1 map的构造
------------
    Template<class T1, class T2>
    map(); // 默认构造函数
    map(const map& m) // 拷贝构造函数
    map(iterator begin, iterator end ); //区间构造函数
    map(iterator begin, iterator end, const traits& _compare) //带比较谓词的构造函数
    map(iterator begin, iterator end, const traits& _compare, const allocator& all) //带分配器
    
  1.2 map定义
----------------
    1.2.1map的基本定义
    map对象是模板类，需要关键字和存储对象两个模板参数：
    std:map<int, string> personnel;
    这样就定义了一个用int作为索引,并拥有相关联的指向string的指针.
    为了使用方便，可以对模板类进行一下类型定义：
    typedef map<int, CString> UDT_MAP_INT_CSTRING;
    UDT_MAP_INT_CSTRING enumMap; //后面会依此例说明
    1.2.2 map的嵌套定义
    map<sring,map<string,long> > //注意：最后两个>之间有个空格
    map支持下标运算符operator[]，用访问普通数组的方式来访问map；不过下标为map的键，在multimap中一个键可以对应多个不同的值。
  
2.map的方法
------------
2.1 在map中插入元素
------------
    三种插入方式：
    2.1.1用insert方法插入pair对象：
     enumMap.insert(pair<int, Cstring>(1, “One”));
    2.1.2 用insert方法插入value_type对象：
     enumMap.insert(map<int, Cstring>::value_type (1, “One”));
    2.1.3 用数组方式插入值：
     enumMap[1] = "One";
    enumMap[2] = "Two";
    ......
    这样非常直观，但存在一个性能的问题。插入2时,先在enumMap中查找主键为2的项，没发现，然后将一个新的对象插入enumMap，键是2，值是一个空字符串，插入完成后，将字符串赋为"Two"; 该方法会将每个值都赋为缺省值，然后再赋为显示的值，如果元素是类对象，则开销比较大。用前两种方法可以避免开销。
    
2.2 查找并获取map中元素
--------------------
    2.2.1下标操作符给出了获得一个值的最简单方法：
    CString tmp = enumMap[2];
    但是,只有当map中有这个键的实例时才对，否则会自动插入一个实例，值为初始化值。
    2.2.2我们可以使用find()和count()方法来发现一个键是否存在
    查找map中是否包含某个关键字条目用find()方法，传入的参数是要查找的key，在这里需要提到的是begin()和end()两个成员，分别代表map对象中第一个条目和最后一个条目，这两个数据的类型是iterator.
    int nFindKey = 2; //要查找的Key
    //定义一个条目变量(实际是指针)
    UDT_MAP_INT_CSTRING::iterator it= enumMap.find(nFindKey);
    if(it == enumMap.end()) {
    cout<<"没找到"<<endl;
    }
    else {
    cout<<"找到了"<<endl;
    }
    通过map对象的方法获取的iterator数据类型是一个std::pair对象，包括两个数据。
    iterator->first 关键字(key)
    iterator->second 存储的数据(value)
    
  2.3 从map中删除元素
-------------------------
    2.3.1移除某个map中某个条目用erase()
    该成员方法的定义如下：
    1．iterator erase(iterator it); //通过一个条目对象删除
    2．iterator erase(iterator first, iterator last); //删除一个范围
    3．size_type erase(const Key& key); //通过关键字删除
    2.3.2清除所有的元素clear()
    clear()就相当于 enumMap.erase(enumMap.begin(), enumMap.end());
  2.4 map中swap的用法
----------------
    map中的swap不是一个容器中的元素交换，而是两个容器交换；
    For example：
    #include <map>
    #include <iostream>
    using namespace std;
    int main( )
    {
    map <int, int> m1, m2, m3;
    map <int, int>::iterator m1_Iter;
    m1.insert ( pair <int, int> ( 1, 10 ) );
    m1.insert ( pair <int, int> ( 2, 20 ) );
    m1.insert ( pair <int, int> ( 3, 30 ) );
    m2.insert ( pair <int, int> ( 10, 100 ) );
    m2.insert ( pair <int, int> ( 20, 200 ) );
    m3.insert ( pair <int, int> ( 30, 300 ) );
    cout << "The original map m1 is:";
    for ( m1_Iter = m1.begin( ); m1_Iter != m1.end( ); m1_Iter++ )
    cout << " " << m1_Iter->second;
    cout << "." << endl;
    // This is the member function version of swap
    //m2 is said to be the argument map; m1 the target map
    m1.swap( m2 );
    cout << "After swapping with m2, map m1 is:";
    for ( m1_Iter = m1.begin( ); m1_Iter != m1.end( ); m1_Iter++ )
    cout << " " << m1_Iter -> second;
    cout << "." << endl;
    cout << "After swapping with m2, map m2 is:";
    for ( m1_Iter = m2.begin( ); m1_Iter != m2.end( ); m1_Iter++ )
    cout << " " << m1_Iter -> second;
    cout << "." << endl;
    // This is the specialized template version of swap
    swap( m1, m3 );
    cout << "After swapping with m3, map m1 is:";
    for ( m1_Iter = m1.begin( ); m1_Iter != m1.end( ); m1_Iter++ )
    cout << " " << m1_Iter -> second;
    cout << "." << endl;
    }
  2.5 map的sort问题
-------------------  
    Map中的元素是自动按key升序排序,所以不能对map用sort函数：
    For example：
    #include <map>
    #include <iostream>
    using namespace std;
    int main( )
    {
    map <int, int> m1;
    map <int, int>::iterator m1_Iter;
    m1.insert ( pair <int, int> ( 1, 20 ) );
    m1.insert ( pair <int, int> ( 4, 40 ) );
    m1.insert ( pair <int, int> ( 3, 60 ) );
    m1.insert ( pair <int, int> ( 2, 50 ) );
    m1.insert ( pair <int, int> ( 6, 40 ) );
    m1.insert ( pair <int, int> ( 7, 30 ) );
    cout << "The original map m1 is:"<<endl;
    for ( m1_Iter = m1.begin( ); m1_Iter != m1.end( ); m1_Iter++ )
    cout << m1_Iter->first<<" "<<m1_Iter->second<<endl;
    }
    The original map m1 is:
    1 20
    2 50
    3 60
    4 40
    6 40
    7 30
    请按任意键继续. . .
  2.6 map的基本操作函数
-----------------  
    C++ Maps是一种关联式容器，包含“关键字/值”对
    begin() 返回指向map头部的迭代器
    clear(） 删除所有元素
    count() 返回指定元素出现的次数
    empty() 如果map为空则返回true
    end() 返回指向map末尾的迭代器
    equal_range() 返回特殊条目的迭代器对
    erase() 删除一个元素
    find() 查找一个元素
    get_allocator() 返回map的配置器
    insert() 插入元素
    key_comp() 返回比较元素key的函数
    lower_bound() 返回键值>=给定元素的第一个位置
    max_size() 返回可以容纳的最大元素个数
    rbegin() 返回一个指向map尾部的逆向迭代器
    rend() 返回一个指向map头部的逆向迭代器
    size() 返回map中元素的个数
    swap() 交换两个map
    upper_bound() 返回键值>给定元素的第一个位置
    value_comp() 返回比较元素value的函数
 
  3.例子
-----------------
```c
    #include <iostream>
    #include <map>
    using namespace std;
    int main(void)
    {
      map<char,int,less<char> > map1;
      map<char,int,less<char> >::iterator mapIter;
      //char 是键的类型，int是值的类型
      //下面是初始化，与数组类似
      //也可以用map1.insert(map<char,int,less<char> >::value_type('c',3));
      map1['c']=3;
      map1['d']=4;
      map1['a']=1;
      map1['b']=2;
      for(mapIter=map1.begin();mapIter!=map1.end();++mapIter)
        cout<<" "<<(*mapIter).first<<": "<<(*mapIter).second;
      //first对应定义中的char键，second对应定义中的int值
      //检索对应于d键的值是这样做的：
      map<char,int,less<char> >::const_iterator ptr;
      ptr=map1.find('d');
      cout<<''\n''<<" "<<(*ptr).first<<" 键对应于值："<<(*ptr).second;
      cin.get();
      return 0;
    }
```
    从以上例程中，我们可以看到map对象的行为和一般数组的行为类似。Map允许两个或多个值使用比较操作符。下面我们再看看multimap:
```c
    #include <iostream>
    #include <map>
    #include <string>
    using namespace std;
    int main(void)
    {
      multimap<string,string,less<string> >mulmap;
      multimap<string,string,less<string> >::iterator p;
      //初始化多重映射mulmap:
      typedef multimap<string,string,less<string> >::value_type vt;
      typedef string s;
      mulmap.insert(vt(s("Tom "),s("is a student")));
      mulmap.insert(vt(s("Tom "),s("is a boy")));
      mulmap.insert(vt(s("Tom "),s("is a bad boy of blue!")));
      mulmap.insert(vt(s("Jerry "),s("is a student")));
      mulmap.insert(vt(s("Jerry "),s("is a beatutiful girl")));
      mulmap.insert(vt(s("DJ "),s("is a student")));
      //输出初始化以后的多重映射mulmap:
      for(p=mulmap.begin();p!=mulmap.end();++p)
        cout<<(*p).first<<(*p).second<<endl;
      //检索并输出Jerry键所对应的所有的值
      cout<<"find Jerry :"<<endl;
      p=mulmap.find(s("Jerry "));
      while((*p).first=="Jerry ")
      {
        cout<<(*p).first<<(*p).second<<endl;
        ++p;
      }
      cin.get();
      return 0;
    }
```
    在map中是不允许一个键对应多个值的，在multimap中，不支持operator[],也就是说不支持map中允许的下标操作。
