#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {

    string title = "Ozarow";

    if (argc > 1) {
        title = argv[1];
    }

    cout << "<!DOCTYPE html>\n";
    cout << "<html>\n";
    cout << "  <head>\n";
    cout << "    <meta charset=\"UTF-8\">\n";
    cout << "    <title>" << title << "</title>\n";
    cout << "  </head>\n";
    cout << "  <body>\n";

    cout << R"(
    <h1>Ozarow attractions</h1>
    <h2>Kościół pw. św. Stanisława Biskupa</h2>
    <img src="костел.jpeg" alt="" align="left" width="400px" hspace="10" vspace="6">
    <p>Historia: Pierwszy kościół w Ożarowie był drewniany, prawdopodobnie powstał już w XVI wieku.
    Był on wielokrotnie odnawiany i przebudowywany.
    Budowa obecnego kościoła: Świątynia murowana została wybudowana w latach 1887–1900 z kamienia janikowskiego.
    Ma kształt krzyża i dwie wieże.</p>

    <br clear="all">
    <h2>2. Stadion Alit Ożarów</h2>
    <img src="Untitled.jpeg" width="400px" align="left" hspace="10" vspace="6">
    <p>Pełna nazwa: Stadion Miejski Alit Ożarów<br>
    Lokalizacja: ul. Leśna 2, 27-530 Ożarów<br>
    Pojemność: około 950 miejsc (w tym ok. 550 siedzących)<br>
    Dodatkowe obiekty: bieżnia lekkoatletyczna, korty tenisowe, boisko wielofunkcyjne</p>

    <br clear="all">
    <h2>3. Zapka</h2>
    <img src="images.jpeg" width="400" align="left" hspace="10" vspace="6">
    <p>Sklep Żabka, ul. Jana Pawła II 10, 27-530 Ożarów — czynny codziennie od 06:00 do 23:00.
    Żabka w Ożarowie ma też swoje promocje i gazetki, można je sprawdzić online.</p>

    <br clear="all">
    <h2>4. Biedronka</h2>
    <img src="5355311012926062317.jpg" width="400px" align="left" hspace="10" vspace="6">
    <p>Biedronka, Pl. Wolności 14, Ożarów, korty tenisowe, boisko wielofunkcyjne. 
    Godziny działania: obiekt czynny в różnych godzinach — в dni powszednie и weekendy; szczególnie w sezonie treningowym i sportowym; wymaga rezerwacji в niektórych przypadkach.</p>
    )";

    cout << "  </body>\n</html>\n";

    return 0;
}
