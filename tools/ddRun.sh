#!/bin/bash

OUTDIR="$1"
PROG=/home/catC/de283294/projet_gradient/cpp/test_gradient

# valgrind --tool=verrou --rounding-mode=random --float=yes $PROG > $OUTDIR/res.dat
valgrind --tool=verrou --float=yes $PROG > $OUTDIR/res.dat

