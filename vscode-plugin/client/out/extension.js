"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.deactivate = exports.activate = void 0;
const path = require("path");
const vscode_1 = require("vscode");
const node_1 = require("vscode-languageclient/node");
const net = require("net");
const child_process_1 = require("child_process");
const term = require("terminate");
let client;
let server;
let exited = false;
function activate(context) {
    const getLspFileName = function () {
        switch (process.platform) {
            case "win32":
                return "lsp.exe";
            case "linux":
                return "lsp";
            default:
                throw new Error("No Version for your OS is bundled.");
        }
    };
    // The server is implemented in node
    const serverModule = context.asAbsolutePath(path.join("client", "lsp", getLspFileName()));
    server = (0, child_process_1.execFile)(serverModule + " --port 5007 --disabledLog", {
        shell: true
    }, (error, stdout, stderr) => {
        if (error) {
            throw error;
        }
        console.log(stdout);
        console.log(stderr);
    });
    server.on('exit', (exit) => {
        console.log("Server exited");
        exited = true;
    });
    // The server is a started as a separate app and listens on port 5007
    let connectionInfo = {
        port: 5007
    };
    let serverOptions = () => {
        // Connect to language server via socket
        let socket = net.connect(connectionInfo);
        let result = {
            writer: socket,
            reader: socket
        };
        return Promise.resolve(result);
    };
    // Options to control the language client
    const clientOptions = {
        // Register the server for all documents by default
        documentSelector: [{ scheme: "file", language: "dmf", pattern: "**/*.dmf" }],
        synchronize: {
            // Notify the server about file changes to '.clientrc files contained in the workspace
            fileEvents: vscode_1.workspace.createFileSystemWatcher("**/.clientrc"),
        },
    };
    // Create the language client and start the client.
    client = new node_1.LanguageClient("dmf", "DMF Server", serverOptions, clientOptions);
    // Start the client. This will also launch the server
    client.start();
}
exports.activate = activate;
async function deactivate() {
    const cleanupPromises = [];
    if (!client) {
        return undefined;
    }
    let promise = client.stop();
    cleanupPromises.push(promise);
    console.log("Stopping Server");
    cleanupPromises.push(new Promise((resolve, reject) => {
        term.default(server.pid, err => {
            if (err == null) {
                resolve(null);
            }
            else {
                reject(err);
            }
        });
    }));
    await Promise.all(cleanupPromises);
}
exports.deactivate = deactivate;
//# sourceMappingURL=extension.js.map