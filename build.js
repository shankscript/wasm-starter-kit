const fs = require('fs-extra');
const { exec } = require('child_process');

fs.emptyDirSync('./dist');

exec(`emcc -o dist/index.html src/ecms.c -O3 -g -s WASM=1 --shell-file src/template.html -s NO_EXIT_RUNTIME=1 -s EXTRA_EXPORTED_RUNTIME_METHODS='["ccall","cwrap"]' --source-map-base http://localhost:8888/`, (err, stdout, stderr) => {
    if (err) {
        // node couldn't execute the command
        console.error('E!!!!!!!', err);
        return;
    }
    fs.copySync('./src', './dist/src');
    console.log(`stdout: ${stdout}`);
    console.log(`stderr: ${stderr}`);
});