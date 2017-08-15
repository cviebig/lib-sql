SQL parse tree
==============

This package defines a SQL parse tree that aims to be compatible with the syntax
definition provided by the SQLite3 manual [1]. Altough it's not complete it
covers mostly ``SELECT`` and ``CREATE TABLE`` statements as well as a
proprietary syntax addition for importing from delimiter separated files.

Boost Fusion bindings are provided in `include/sql/fusion/
<include/sql/fusion/>`_ and a parsing expression grammar based on Boost Spirit
X3 is provided in ``lib-sql-text`` [2].

[1] https://www.sqlite.org/lang.html

[2] https://github.com/cviebig/lib-sql-text
