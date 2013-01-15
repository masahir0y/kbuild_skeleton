kbuild_skeleton
===============

A template with Linux Kernel like build system (Kbuild).

Writing a basic makefile for a small project is fairly simple.
But when you maintain a large project, you will probably need more than just
basics: automatic dependency tracking, recursive builds in subdirectories,
and so on.
Instead of implementing those functions by yourself, you can use Autotools
(Autoconf/Automake/Libtool). Especially, you are following GNU Coding
Standards,
Autotools would be a best choice.
Otherwise, Kbuild are also quite powerful, recommended build system.
Now some open source projects such as busybox, are using Kbuild,
although, originally, kbuild system were written for Linux Kernel.

This project includes a pretty simple application with Kbuild system.
Some files needed for Kbuild features were copied from Linux Kernel.
Copied files include the top-level `Makefile` and some helper programs and
makefiles under `scripts/` directory.
They were modified for simplisity because modules support are not necessary
for general applications.

I hope this template will be a good startpoint of your new project.

Building
--------

        make config    # This creates a file called ".config"
        make           # This creates an executable

These steps generate a small application `myapp`,
which just print some messages to the console.

The full list of configuration and build targets is available by:

        make help

How to use this template?
-------------------------

This project includes a small program called `myapp` just for example.
So when you start your own project, replace C source files of `myapp`
with those of your own.
C source files of `myapp` are located under `lib/` and `main/` and `include/`.
If you don't need them, delete all of them.
Although, of course, you can still reuse them for your own project.
You will also need to modify `Kconfig` for your project.

In order to change the name of application, modify the top-level Makefile.

        grep -i myapp *

will show the lines where `myapp` string are used.
Modify those `myapp` strings with your application name.

You can add more subdirectories by adding to `objs-y` or `libs-y` variables
of top-level `Makefile`.
For `myapp`, these variable are set as follows:

        objs-y          := main
        libs-y          := lib

In this case, all objectes under `main/` subdirectory are combined together
into `main/builtin.o`, and all objects under `lib/` subdirectory are archived
as `lib/lib.a`.
Finally, they are linked to generate the final application, `myapp`.

About the detail of how to write makefiles under subdirectories, refer to:
`Documentation/kbuild/makefiles.txt`.

About how to write Kconfig, refer to:
`Documentation/kbuild/kconfig-language.txt`.

Both of them were copied from Linux Kernel Documentation.
