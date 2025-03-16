"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.deactivate = exports.activate = void 0;
const path = require("path");
const vscode_1 = require("vscode");
const node_1 = require("vscode-languageclient/node");
const net = require("net");
const child_process_1 = require("child_process");
let client;
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
    // console.log(serverModule)
    // console.log("exists:", fs.existsSync(serverModule))
    const child = (0, child_process_1.execFile)(serverModule + " --port 5007 --disabledLog", {
        shell: true
    }, (error, stdout, stderr) => {
        if (error) {
            throw error;
        }
        console.log(stdout);
        console.log(stderr);
    });
    // The server is a started as a separate app and listens on port 5007
    let connectionInfo = {
        port: 5007
    };
    //  const runExe = { module: serverModule, transport: TransportKind.stdio };
    //  const runExe: Executable = { command: serverModule, transport: TransportKind.stdio, options: {shell: false, detached: false } };
    const runExe = { command: serverModule, transport: node_1.TransportKind.stdio, options: { shell: false, detached: false } };
    // If the extension is launched in debug mode then the debug server options are used
    // Otherwise the run options are used
    // const serverOptions: ServerOptions = {
    //   run: runExe,
    //   debug: runExe,
    // };
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
function deactivate() {
    if (!client) {
        return undefined;
    }
    return client.stop();
}
exports.deactivate = deactivate;
//# sourceMappingURL=extension.js.map