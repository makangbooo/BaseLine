import torch
from torch import nn
from d2l import torch as d2l

""" 
将一个句子或两个句子作为输入, 返回BERT输入序列的标记及其相应的段索引 
    CLS: 句子对的开始标记
    SEP: 句子对的分隔标记
    0: 句子A的标记
    1: 句子B的标记
"""
def get_tokens_and_segments(tokens_a, tokens_b=None):
    """ 获取输入序列的词元和分段信息 """
    tokens = ['<CLS>'] + tokens_a + ['<SEP>']
    # 0和1分别表示段A和段B
    segments = [0] * (len(tokens_a) + 2)
    if tokens_b is not None:
        tokens += tokens_b + ['<SEP>']
        segments += [1] * (len(tokens_b) + 1)
        return tokens, segments

"""encoder类"""
class BERTEncoder(nn.Module):
    """BERT编码器"""
    def __init__(self, vocab_size, num_hiddens, norm_shape, ffn_num_input, ffn_num_hiddens, num_heads,
                 num_layers,dropout, max_len=1000, key_size=768, query_size=768, value_size=768, **kwargs):

        super(BERTEncoder, self).__init__(**kwargs)
        self.token_embedding = nn.Embedding(vocab_size, num_hiddens)
        self.segment_embedding = nn.Embedding(2, num_hiddens)
        self.blks = nn.Sequential()
        for i in range(num_layers):
            self.blks.add_module(f'{i}', d2l.EncoderBlock(
                key_size, query_size, value_size, num_hiddens, norm_shape, ffn_num_input,
                ffn_num_hiddens, num_heads, dropout, True))




        self.embedding = nn.Embedding(vocab_size, num_hiddens)
        self.pos_embedding = nn.Embedding(max_len, num_hiddens)
        self.segment_embedding = nn.Embedding(2, num_hiddens)
        self.dropout = nn.Dropout(dropout)
        self.encoder_layers = nn.ModuleList([
            nn.TransformerEncoderLayer(num_hiddens, num_heads) for _ in range(num_layers)
        ])
    
    def forward(self, tokens, segments):
        # 词嵌入
        X = self.embedding(tokens) + self.pos_embedding(torch.arange(tokens.shape[1], device=tokens.device)) + self.segment_embedding(segments)
        X = self.dropout(X)
        
        # 编码器
        for layer in self.encoder_layers:
            X = layer(X)
        
        return X

