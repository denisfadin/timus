f = open( './test3', 'w' )
n = 100000
f.write( str(n)+'\n' )
for x in range(n, 0, -1):
   f.write( 'getMin ' + str( x ) + '\n' );
f.close();
