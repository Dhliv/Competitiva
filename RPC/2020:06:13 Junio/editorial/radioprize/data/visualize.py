#!/usr/bin/env python3

# plot radioprize input data as SVG

import argparse
import re
import subprocess

def visualize():
    p = argparse.ArgumentParser()
    p.add_argument('--maxn', type=int, default=25, help='maximum number of nodes to render (to avoid absurdly large diagrams)')
    p.add_argument('--type', choices=['svg', 'png', 'jpg', 'pdf'], default='svg')
    p.add_argument('input_files', nargs='+', help='the .in files to render')
    args = p.parse_args()

    for input_filename in args.input_files:
        output_filename = re.sub('[.]in$', '.' + args.type, input_filename)

        print('rendering {} into {}'.format(input_filename, output_filename))

        with open(input_filename) as input_file:
            n = int(input_file.readline())

            if n > args.maxn:
                print('skipping rendering {} as the number of nodes is too large ({}; see --maxn)'.format(output_filename, n))
                continue

            node_values = list(map(int, input_file.readline().split()))

            edges = [tuple(map(int, line.split())) for line in input_file]

        graph_lines = ['graph G {', 'rankdir=LR;']

        for i in range(n):
            graph_lines.append('{0} [label="t{0}={1}"];'.format(i+1, node_values[i]))

        for u, v, w in edges:
            graph_lines.append('{} -- {} [label="{}"];'.format(u, v, w))

        graph_lines.append('}');

        with open(output_filename, 'w') as out:
            p = subprocess.Popen(['dot', '-T', args.type], stdin=subprocess.PIPE, stdout=out)
            graph = '\n'.join(graph_lines)
            (out, err) = p.communicate(bytes(graph, 'utf-8'))

if __name__ == '__main__':
    visualize()

