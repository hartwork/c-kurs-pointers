base = c-kurs-pointers-pipping
viewer = okular
tempdir = tmp

graphics-pdfs = $(patsubst %.svg,%.pdf,$(wildcard graphics/*.svg))
creative-commons-pdfs = $(patsubst %.svg,%.pdf,$(wildcard creative-commons/*.svg))
pdfs = $(graphics-pdfs) $(creative-commons-pdfs)

all: $(base)-print.pdf $(base)-live.pdf

$(pdfs): %.pdf: %.svg
	inkscape "--export-pdf=$@" "$<"

$(base)-live.pdf: $(tempdir)/$(base)-live.pdf
	cp "$(tempdir)/$(base)-live.pdf" "$(base)-live.pdf"

$(base)-print.pdf: $(tempdir)/$(base)-print.pdf
	cp "$(tempdir)/$(base)-print.pdf" "$(base)-print.pdf"

$(tempdir)/$(base)-live.pdf: $(base)-live.tex $(base).tex content.tex beamerthemeManhattan.sty $(pdfs) VERSION.tex
	mkdir -p $(tempdir)
	pdflatex -halt-on-error -output-directory $(tempdir) $(base)-live.tex
	pdflatex -halt-on-error -output-directory $(tempdir) $(base)-live.tex

$(tempdir)/$(base)-print.pdf: $(base)-print.tex $(base).tex content.tex beamerthemeManhattan.sty $(pdfs) VERSION.tex
	mkdir -p $(tempdir)
	pdflatex -halt-on-error -output-directory $(tempdir) $(base)-print.tex
	pdflatex -halt-on-error -output-directory $(tempdir) $(base)-print.tex

VERSION.tex: .git .git/refs/tags
	git describe --tags | sed 's/-\([0-9]\+\)-.*/.\1/' > VERSION.tex

content.tex: content.txt
	wiki2beamer content.txt > content.tex

clean:
	-rm -vf *~
	-rm -vf "$(tempdir)"/*
	-rm -vf $(graphics-pdfs) $(creative-commons-pdfs)

distclean: clean
	-rm -vf $(base).pdf $(base)-*.tex

view: all
	$(viewer) $(base).pdf &


# Workaround for tarball
.git:
	mkdir -p .git
	touch VERSION.tex

.git/refs/tags: .git
	mkdir -p .git/refs
	touch .git/refs/tags
	touch VERSION.tex
