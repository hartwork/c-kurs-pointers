base = c-kurs-pointers-pipping
viewer = kpdf
tempdir = tmp

graphics-pdfs = $(patsubst %.svg,%.pdf,$(wildcard graphics/*.svg))
creative-commons-pdfs = $(patsubst %.svg,%.pdf,$(wildcard creative-commons/*.svg))
pdfs = $(graphics-pdfs) $(creative-commons-pdfs)

all: $(base).pdf

$(pdfs): %.pdf: %.svg
	inkscape "--export-pdf=$@" "$<"

$(base).pdf: $(tempdir)/$(base).pdf
	cp "$(tempdir)/$(base).pdf" "$(base).pdf"

$(tempdir)/$(base).pdf: $(base).tex content.tex beamerthemeManhattan.sty $(pdfs) VERSION.tex
	mkdir -p $(tempdir)
	pdflatex -halt-on-error -output-directory $(tempdir) $(base).tex
	pdflatex -halt-on-error -output-directory $(tempdir) $(base).tex

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
