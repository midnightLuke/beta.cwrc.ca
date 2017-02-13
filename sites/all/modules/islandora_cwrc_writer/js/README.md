The js directory is laid out to match that of the CWRC-Writer, any files you
come across aside from islandora_cwrc_writer*.js should map to the files
found in CWRC-Writer/src/js. Our goal with this code is to use as much of the
CWRC-Writer code base as possible and only overload it where it's truly
necessary.

What we will attempt to do is to define our own functions and objects that
replace the CWRC-Writer objects after initialization. That way we should be able
to update the CWRC-Writer code without changing much if any of our code.

We'll use the global object "Drupal.CWRCWriter" to store our custom
functionality it's objects should match the hierarchy of objects within the
CWRC-Writer's "Writer" object. The CWRC-Writer's "Writer" object can be accessed
via "Drupal.CWRCWriter.writer".
