/*
METODOS EN LAS NOTICIAS:


PASAR NOTICIA AL FRENTE (ANNADIR LUEGO DEL CURSOR)                                             News toFront(titular noticia); asi sirve add

BORRAR NOTICIA (REMOVE())                                                                      News delete(titular noticia);

BUSCAR PALABRAS (ITERATE() Y BUSCAR AHI)                                                       News searchWord(string word);

ENSENNAR POR RELEVANCIA (ORDENANDO POR FECHA, CON SEARCHWORD() TOFRONT() ENTRE OTROS)          News displayRelevance();

RELEVANCIA POR INPUT( SIMILAR A SEARCHWORD() PERO SOLO LAS PALABRAS DEL INPUT)                 News searchInput(array input);

ELIMINAR POR INPUT( SIMILAR A SEARCHINPUT() PERO LO QUE HACE ES BORRAR NOTICIAS)               News deleteInput(array input);

REUBICAR NOTICIA(USANDO COUNTNODES() Y SHOWPOSITIONS() ENCUENTRA LAS POSICIONES                void reubicate(int n, string+-m);
PARA LUEGO HACIENDO ADVANCE PODER ANNADIR LA NOTICIA EN SU NUEVA POSICION )


*/