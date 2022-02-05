#include "principal.h"

#include <QApplication>
#include <QTranslator>
//Iconos descargados de https://www.flaticon.es/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLocale::setDefault(QLocale::English);
    QTranslator traduccion;
   // Solicitando al usuario que seleccione un idioma
    QStringList idiomas;
    idiomas << "Ingles"<< "Español";
    QString idiomaSeleccionado = QInputDialog::getItem(NULL,
                                                       "Idioma",
                                                       "Seleccione un idioma",
                                                       idiomas);
    // Dependiendo del idioma seleccionado, carga el archivo de rtaducción
    if (idiomaSeleccionado == "Ingles"){
        traduccion.load(":/MiPaint_en.qm");
    }
    // Si es diferente de español, se instala la traducción en TODA la aplicación
    if (idiomaSeleccionado != "Español"){
        a.installTranslator(&traduccion);
    }

    Principal w;
    w.show();
    return a.exec();
}
