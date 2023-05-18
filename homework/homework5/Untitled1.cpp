
template <typename T> //©ЛкыеепР
void Vector<T>::quickSort ( Rank lo, Rank hi ) {
	if ( hi - lo  < 2 ) return ;
	Rank mi = partition ( lo, hi - 1 );
	quickSort ( lo, mi );
	qiuckSort ( mi, hi -1 );
} 


template <typename T>
Rank Vector<T>::partition ( Rank lo, Rank hi ) {
	swape ( _elem[lo],_elem[ lo + rank() % ( hi - lo +1 ) ]);
} 


