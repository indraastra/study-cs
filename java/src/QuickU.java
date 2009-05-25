/**
 * User: Vishal Talwar
 * Date: May 25, 2009
 * Time: 12:12:06 PM
 * <p/>
 * Quick UNION, slow FIND
 */
public class QuickU {
    public static void main( String[] args ) {
        int N = Integer.parseInt( args[0] );
        int id[] = new int[N];
        for ( int i = 0; i < N; i++ ) {
            id[i] = i;
        }
        for ( In.init(); !In.empty(); ) {
            int i, j, p = In.getInt(), q = In.getInt();
            // find
            for ( i = p; i != id[i]; i = id[i] ) ;
            for ( j = p; j != id[j]; j = id[j] ) ;
            if ( i == j ) {
                continue;
            }
            // union
            id[i] = j;
            Out.println( " " + p + " " + q );
        }
    }
}
