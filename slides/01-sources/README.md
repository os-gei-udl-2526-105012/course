# Introducció a la programació de sistema (I) en C

## Contingut

- **bin**: Conté els binaris generats a partir dels exemples de codi.
- **sources**: Conté els exemples de codi font.
- **files**: Conté els fitxers de text que s'utilitzen com a exemple en els programes.
- **Makefile**: Arxiu de configuració per a la construcció dels binaris.

## Com executar els exemples

- Per a compilar els exemples de codi, només cal executar la següent comanda:

    ```bash
    make
    ```

- Per a netejar els binaris generats, només cal executar la següent comanda:

    ```bash
    make clean
    ```

- Per executar un exemple de codi, només cal executar la següent comanda:

    ```bash
    ./bin/nom_del_programa
    ```

    o bé

    ```bash
    make EXEC=nom_del_programa ARGS=args_del_programa run
    ```
