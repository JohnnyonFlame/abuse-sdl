#!/bin/sh

rm -f abuse.opk
mksquashfs data/ src/abuse doc/abuse.png doc/default.gcw0.desktop doc/abuse.sh abuse.opk

