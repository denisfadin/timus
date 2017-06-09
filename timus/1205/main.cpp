#include <iostream>
#include <vector>
#include <unordered_set>
#include <iomanip>
#include <cmath>

typedef std::pair< double, double > Point;

double lenght( Point const& a, Point const& b )
{
   return sqrt((a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second));
}

double time( Point const& a, Point const& b, double const& speed )
{
   return lenght( a, b ) / speed;
}

struct hash
{
   size_t operator () ( std::pair< int, int > const& p ) const
   {
      return p.first*201 + p.second;
   }
};

int main()
{
   double foot_speed, metro_speed;
   std::cin >> foot_speed >> metro_speed;

   int N;
   std::cin >> N;

   std::vector< Point > stations;
   for( int i = 0; i < N; ++i )
   {
      double x, y;
      std::cin >> x >> y;
      stations.emplace_back( std::make_pair( std::move( x ), std::move( y ) ) );
   }

   std::unordered_set< std::pair<int,int>, hash > graph;
   {
      int x, y;
      while( true )
      {
         if( 0 == x && 0 == y )
            break;
         std::cin >> x >> y;
         graph.emplace( std::make_pair( x-1, y-1 ) );
         graph.emplace( std::make_pair( y-1, x-1 ) );
      }
   }

   Point a;
   std::cin >> a.first >> a.second;

   Point b;
   std::cin >> b.first >> b.second;
   stations.emplace_back( b );

   std::vector< double > a_time;
   std::vector< std::vector< int > > a_metro;
   std::vector< bool > marked;
   for( int i = 0; i <= N; ++i )
   {
      a_time.emplace_back( time( a, stations[i], foot_speed ) );
      marked.push_back( false );

      std::vector< int > v;
      if( i != N )
         v.emplace_back( i+1 );
      a_metro.emplace_back( std::move(v) );
   }

   double const MAX_TIME = a_time.back();

   auto find_next = [&]( int& num ) -> bool {
      double min = MAX_TIME;
      num = -1;
      for( int i = 0; i <= N; ++i )
      {
         if( !marked[i] && min > a_time[i] )
         {
            min = a_time[i];
            num = i;
         }
      }
      return num != -1;
   };

   int num = -1;
   while( find_next( num ) )
   {
      marked[num] = true;
      for( int i = 0; i <= N; ++i )
      {
         if( num == i )
            continue;

         double t;
         bool metro = false;
         auto it = graph.find( std::make_pair( num, i ) );
         if( it != graph.end() ) // едем на метро
         {
            t = time( stations[num], stations[i], metro_speed );
         }
         else // идем пешком
         {
            t = time( stations[num], stations[i], foot_speed );
         }

         if( a_time[i] > a_time[num] + t )
         {
             a_time[i] = a_time[num] + t;

             a_metro[i] = a_metro[num];
             if( i != N )
                a_metro[i].emplace_back( i+1 );
         }
      }
   }

   std::cout << std::fixed << std::setprecision(7) << a_time[N] << std::endl;
   std::cout << a_metro[N].size() << " ";
   for( auto it = a_metro[N].begin(); it != a_metro[N].end(); ++it )
      std::cout << *it << " ";

   return 0;
}
