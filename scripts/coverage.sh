

mkdir coverage
lcov -d . -t tests coverage/lcov.info -b . -c --no-external
