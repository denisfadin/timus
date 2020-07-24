f = open( './test', 'w' )
n = 100000
f.write( str(n)+'\n' )
for x in range(1, n):
   f.write( str( x ) + ' ' + str( x+1 ) + '\n' );
f.close();
