#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql.h>
#include <stdarg.h>
#include <errno.h>


#define QUERY_SIZE 256

#define BUFFER_SIZE 80

static void error_fatal (char *format, ...);

int
main (int argc, char **argv)
{
    MYSQL *konekcija;
    MYSQL_RES *rezultat;
    MYSQL_ROW red;
    MYSQL_FIELD *polje;
    int i;
    int broj;

    char query[QUERY_SIZE];
    char buffer[BUFFER_SIZE];

    konekcija = mysql_init (NULL);
    
    if (mysql_real_connect
        (konekcija, "localhost", "nikola", "nikola", "veleprodaja", 0, NULL,
        0) == NULL)
        error_fatal ("Greska u konekciji. %s\n", mysql_error (konekcija));

    sprintf (query, "select * from Proizvod");

    if (mysql_query (konekcija, query) != 0)
        error_fatal ("Greska u upitu %s\n", mysql_error (konekcija));
    
    rezultat = mysql_use_result (konekcija);

    polje = mysql_fetch_field (rezultat);

    printf ("PROIZVODI:\n");
    
    printf ("%s\t%s\t\t%s\n", polje[0].name, polje[1].name, polje[2].name);  
    
    broj = mysql_num_fields (rezultat);

    while ((red = mysql_fetch_row (rezultat)) != 0){
        for (i = 0; i < broj; i++)
        printf ("%s\t\t", red[i]);
        printf ("\n");
        }
        
    mysql_free_result (rezultat);
    
    sprintf (query, "select * from Stavka");

    if (mysql_query (konekcija, query) != 0)
        error_fatal ("Greska u upitu %s\n", mysql_error (konekcija));
    
    rezultat = mysql_use_result (konekcija);

    polje = mysql_fetch_field (rezultat);

    printf ("STAVKE:\n");
    
    printf ("%s\t%s\t%s\t\t%s\n", polje[0].name, polje[1].name, polje[2].name, polje[3].name);  
    
    broj = mysql_num_fields (rezultat);

    while ((red = mysql_fetch_row (rezultat)) != 0){
        for (i = 0; i < broj; i++)
        printf ("%s\t\t\t", red[i]);
        printf ("\n");
        }
        
    mysql_free_result (rezultat);
    
    sprintf (query, "select idPonuda,Porudzbina_idPorudzbina,Cena,Popust,Prodajna_cena from Ponuda");

    if (mysql_query (konekcija, query) != 0)
        error_fatal ("Greska u upitu %s\n", mysql_error (konekcija));
    
    rezultat = mysql_use_result (konekcija);

    polje = mysql_fetch_field (rezultat);

    printf ("PONUDE:\n");
    
    printf ("%s\t%s\t\%s\t\%s\t\%s\n", polje[0].name, polje[1].name, polje[2].name, polje[3].name, polje[4].name);  
    
    broj = mysql_num_fields (rezultat);

    while ((red = mysql_fetch_row (rezultat)) != 0){
        for (i = 0; i < broj; i++)
        printf ("%s\t\t", red[i]);
        printf ("\n");
        }
        
    mysql_free_result (rezultat);
    
    int idDokumenta;
    int idProizvoda;
    int kolicina;
    printf("Unosenje nove stavke.\nUnesite idDokumenta(Ponude):");
    scanf("%d", &idDokumenta);
    
    printf("Unesite idProizvoda:\n");
    scanf("%d", &idProizvoda);
  
    printf("Navedite kolicinu proizvoda:\n");
    scanf("%d", &kolicina);

    sprintf(query, "INSERT INTO `Stavka` (idDokumenta,Proizvodi_idProizvodi,Kolicina) VALUES (\"%d\",\"%d\",\"%d\");", idDokumenta,idProizvoda,kolicina);

    if (mysql_query(konekcija, query) != 0)
        error_fatal("Greska u upitu %s\n", mysql_error (konekcija));
        
    mysql_free_result (rezultat);  
    
    sprintf (query, "select * from Proizvod");

    if (mysql_query (konekcija, query) != 0)
        error_fatal ("Greska u upitu %s\n", mysql_error (konekcija));
    
    rezultat = mysql_use_result (konekcija);

    polje = mysql_fetch_field (rezultat);

    printf ("PROIZVODI:\n");
    
    printf ("%s\t%s\t\t%s\n", polje[0].name, polje[1].name, polje[2].name);  
    
    broj = mysql_num_fields (rezultat);

    while ((red = mysql_fetch_row (rezultat)) != 0){
        for (i = 0; i < broj; i++)
        printf ("%s\t\t", red[i]);
        printf ("\n");
        }
        
    mysql_free_result (rezultat);
    
    sprintf (query, "select * from Stavka");

    if (mysql_query (konekcija, query) != 0)
        error_fatal ("Greska u upitu %s\n", mysql_error (konekcija));
    
    rezultat = mysql_use_result (konekcija);

    polje = mysql_fetch_field (rezultat);

    printf ("STAVKE:\n");
    
    printf ("%s\t%s\t%s\t\t%s\n", polje[0].name, polje[1].name, polje[2].name, polje[3].name);  
    
    broj = mysql_num_fields (rezultat);

    while ((red = mysql_fetch_row (rezultat)) != 0){
        for (i = 0; i < broj; i++)
        printf ("%s\t\t\t", red[i]);
        printf ("\n");
        }
        
    mysql_free_result (rezultat);
    
    sprintf (query, "select idPonuda,Porudzbina_idPorudzbina,Cena,Popust,Prodajna_cena from Ponuda");

    if (mysql_query (konekcija, query) != 0)
        error_fatal ("Greska u upitu %s\n", mysql_error (konekcija));
    
    rezultat = mysql_use_result (konekcija);

    polje = mysql_fetch_field (rezultat);

    printf ("PONUDE:\n");
    
    printf ("%s\t%s\t\%s\t\%s\t\%s\n", polje[0].name, polje[1].name, polje[2].name, polje[3].name, polje[4].name);  
    
    broj = mysql_num_fields (rezultat);

    while ((red = mysql_fetch_row (rezultat)) != 0){
        for (i = 0; i < broj; i++)
        printf ("%s\t\t", red[i]);
        printf ("\n");
        }
        
    mysql_free_result (rezultat);
    
    printf("Azuriranje popust na ponudi.\n");
    
    int idPonuda;
    printf("Unesite idPonude:\n");
    scanf("%d", &idPonuda);
    
    int NoviPopust;
    printf("Unesite novi popust:\n");
    scanf("%d", &NoviPopust);

    sprintf(query,  "UPDATE Ponuda SET Popust = \"%d\" WHERE idPonuda = \"%d\";", NoviPopust,idPonuda);

    if (mysql_query(konekcija, query) != 0)
        error_fatal("Greska u upitu %s\n", mysql_error (konekcija));
        
    mysql_free_result (rezultat);  
    
    sprintf (query, "select * from Proizvod");

    if (mysql_query (konekcija, query) != 0)
        error_fatal ("Greska u upitu %s\n", mysql_error (konekcija));
    
    rezultat = mysql_use_result (konekcija);

    polje = mysql_fetch_field (rezultat);

    printf ("PROIZVODI:\n");
    
    printf ("%s\t%s\t\t%s\n", polje[0].name, polje[1].name, polje[2].name);  
    
    broj = mysql_num_fields (rezultat);

    while ((red = mysql_fetch_row (rezultat)) != 0){
        for (i = 0; i < broj; i++)
        printf ("%s\t\t", red[i]);
        printf ("\n");
        }
        
    mysql_free_result (rezultat);
    
    sprintf (query, "select * from Stavka");

    if (mysql_query (konekcija, query) != 0)
        error_fatal ("Greska u upitu %s\n", mysql_error (konekcija));
    
    rezultat = mysql_use_result (konekcija);

    polje = mysql_fetch_field (rezultat);

    printf ("STAVKE:\n");
    
    printf ("%s\t%s\t%s\t\t%s\n", polje[0].name, polje[1].name, polje[2].name, polje[3].name);  
    
    broj = mysql_num_fields (rezultat);

    while ((red = mysql_fetch_row (rezultat)) != 0){
        for (i = 0; i < broj; i++)
        printf ("%s\t\t\t", red[i]);
        printf ("\n");
        }
        
    mysql_free_result (rezultat);
    
    sprintf (query, "select idPonuda,Porudzbina_idPorudzbina,Cena,Popust,Prodajna_cena from Ponuda");

    if (mysql_query (konekcija, query) != 0)
        error_fatal ("Greska u upitu %s\n", mysql_error (konekcija));
    
    rezultat = mysql_use_result (konekcija);

    polje = mysql_fetch_field (rezultat);

    printf ("PONUDE:\n");
    
    printf ("%s\t%s\t\%s\t\%s\t\%s\n", polje[0].name, polje[1].name, polje[2].name, polje[3].name, polje[4].name);  
    
    broj = mysql_num_fields (rezultat);

    while ((red = mysql_fetch_row (rezultat)) != 0){
        for (i = 0; i < broj; i++)
        printf ("%s\t\t", red[i]);
        printf ("\n");
        }
        
    mysql_free_result (rezultat);
    
    mysql_close (konekcija);

    exit(EXIT_SUCCESS);
}

static void error_fatal (char *format, ...)
{
    va_list arguments;		/* Lista argumenata funkcije. */

    /* Stampa se string predstavljen argumentima funkcije. */
    va_start (arguments, format);
    vfprintf (stderr, format, arguments);
    va_end (arguments);

    /* Prekida se program. */
    exit (EXIT_FAILURE);
}
