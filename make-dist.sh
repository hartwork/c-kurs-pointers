#! /bin/sh
self=`basename "$0"`

if [ -z "$1" ]; then
	cat <<-EOF
		USAGE
		  ${self} <version>
		EOF
	exit 1
fi
version=$1
base="c-kurs-pointers-pipping-${version}"

rm -vf "${base}".tar{,.gz}
git archive "--prefix=${base}/" --format=tar -v "--output=${base}.tar" HEAD
gzip -v9 "${base}.tar"
